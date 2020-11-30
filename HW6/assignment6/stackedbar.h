#ifndef STACKEDBAR_H
#define STACKEDBAR_H

#include "character.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_CHARTS_USE_NAMESPACE

class stackedbar
{
    public:
        stackedbar();
        QChartView* show_bar(std::vector<Character>& list_character);
};

#endif // STACKEDBAR_H
