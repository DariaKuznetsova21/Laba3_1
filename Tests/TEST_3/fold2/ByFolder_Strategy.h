#ifndef BYFOLDER_STRATEGY_H
#define BYFOLDER_STRATEGY_H

#include "Strategy.h"

class ByFolder_Calculation : public CalculationStrategy
{
protected:
    void calculate(const QString& path, QMap<QString, qint64>& groups, const QString& currentDir, qint64& total) ;
};

#endif // FOLDERSIZEGROUPER_H
