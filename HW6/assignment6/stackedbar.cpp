#include "stackedbar.h"

stackedbar::stackedbar()
{

}

QChartView* stackedbar::show_bar(std::vector<Character>& list_character)
{
    QStackedBarSeries *series = new QStackedBarSeries();

    QBarSet *hp = new QBarSet("HP");
    QBarSet *attack = new QBarSet("Attack");
    QBarSet *defense = new QBarSet("Defense");

    for (Character c : list_character)
    {
        *hp << c.getHp();
        *attack << c.getAttack();
        *defense << c.getDefense();
    }

    series->append(hp);
    series->append(attack);
    series->append(defense);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Character Stat Comparisons");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;

    for (Character c : list_character)
        categories << QString::fromStdString(c.getName());

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);


    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);


    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);


    return chartView;
}
