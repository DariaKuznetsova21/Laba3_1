#include <QCoreApplication>
#include <QTextStream>
#include "ByFolder_Strategy.h"
#include "ByType_Strategy.h"
#include <stdexcept>
#include <memory>

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);

    while (true) {
        QTextStream cin(stdin);
        QTextStream cout(stdout); //Потоковые ввод и вывод
        std::unique_ptr<CalculationStrategy> context;

        qint64 total = 0;
        QMap<QString, qint64> group; //Контейнер путь - вес в байтах

        QString path; //путь к корневой директории, откуда пойдут расчёты
        cout << "Input path:" << endl;
        cin >> path;

        QString mode; //для выбора стратегии
        cout << "Input mode (1 - folder strategy, 2 - type strategy):" << endl;
        cin >> mode;
        try{
            if (mode == "1") {
                ByFolder_Calculation* calc = new ByFolder_Calculation;
                context.reset(calc);//создает новый объект группировки по размерам папок
                group = context->group(path, total); //метод создает группу файлов в указанном пути
            }

            if (mode == "2") {
                ByType_Calculation* calc = new ByType_Calculation;
                context.reset(calc);//создает новый объект группировки по форматам файлов
                group = context->group(path, total);
            }
        } catch(std::exception& ex) {//выбрасываются исключения
            cout << "Error: " << ex.what() << '\n';
            continue;
        }

        for (auto it = group.begin(); it != group.end(); ++it) { //проходимся по всем элементам карты, пока не достигнем последнего элемента
            QString size_group = QString::number(it.value() / 1024);//преобразуем размер группы в килобайты, а затем в строку
            QString spercent;
            if (total != 0) {
                auto percent = 100 * static_cast<double>(it.value()) / total;//вычисляем процентное соотношение размера текущей группы файлов относительно общего размера всех файлов
                spercent = percent > 0.01 ? QString::number(percent, 'f', 2) : "< 0.01";//Форматируем процент в строку с двумя знаками после запятой, если он больше 0.01
            }
           cout << it.key()<< " size " << size_group << "kb --> " << spercent << "%\n";
        }

        cout << "---------------------------------\n";
    }

    return app.exec();
}
