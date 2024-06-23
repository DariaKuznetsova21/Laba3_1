#ifndef STRATEGY_H
#define STRATEGY_H

#include <QMap>

class CalculationStrategy
{
public:
    virtual ~CalculationStrategy();
    virtual QMap<QString, qint64> group(const QString& path, qint64& total);


protected:
    virtual void calculate(const QString& path, QMap<QString, qint64>& groups, const QString& currentDir, qint64& total) = 0;
};

#endif // SIZEGROUPER_H
