
#ifndef BYTYPE_STRATEGY_H
#define BYTYPE_STRATEGY_H
#include "Strategy.h"

class ByType_Calculation: public CalculationStrategy
{
protected:
    void calculate(const QString& path, QMap<QString, qint64>& groups, const QString& currentDir, qint64& total);
};


#endif // TYPESIZEGROUPER_H
