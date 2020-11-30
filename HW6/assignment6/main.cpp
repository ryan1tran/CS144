#include "stackedbar.h"

int main(int argc, char *argv[])
{
    std::vector<Character> character_vect;
    character_vect.push_back(Character("Furret", 85, 76, 64));
    character_vect.push_back(Character("Wobbuffet", 190, 33, 58));
    character_vect.push_back(Character("Squirtle", 44, 48, 65));
    character_vect.push_back(Character("Ditto", 48, 48, 48));
    character_vect.push_back(Character("Rattata", 30, 56, 35));
    character_vect.push_back(Character("Larvitar", 50, 64, 50));

    stackedbar sb;

    QApplication a(argc, argv);

    QChartView *chartView = sb.show_bar(character_vect);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(600, 400);
    window.show();

    return a.exec();
}
