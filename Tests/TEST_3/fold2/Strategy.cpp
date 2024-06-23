#include "Strategy.h"
#include <QFileInfo>

CalculationStrategy::~CalculationStrategy()
{}

QMap<QString, qint64> CalculationStrategy::group(const QString& path, qint64& total)
{
    QMap<QString, qint64> groups;
    calculate(path, groups, QFileInfo(path).fileName(), total); //метод обрабатывает директорию, группирует файлы, обновляет карту и общий размер всех файлов
    return groups;
}
