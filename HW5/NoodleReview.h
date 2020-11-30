#ifdef __cplusplus
#ifndef NOODLEREVIEW_H
#define NOODLEREVIEW_H

#include <iostream>
#include <vector>
#include <string>

class NoodleReview
{
    public:
        NoodleReview(int reviewNum, std::string brand, std::string variety, std::string style, std::string country, double stars, std::string topTen);
        int get_review_number();
        std::string get_brand();
        std::string get_variety();
        std::string get_style();
        std::string get_country();
        double get_stars();
        std::string get_top_ten();

    private:
        int reviewNum;
        std::string brand;
        std::string variety;
        std::string style;
        std::string country;
        double stars;
        std::string topTen;
};

std::string assemble_noodle_review(NoodleReview& noodle_r);
void display_noodle_reviews(void* nr_list); // set as a void* to avoid circular dependency

#endif
#endif