#include "NoodleReview.h"
#include "LinkedList.h"

std::string assemble_noodle_review(NoodleReview& noodle_r)
{
    return std::to_string(noodle_r.get_review_number()) + ", " +
           noodle_r.get_brand() + ", " +
           noodle_r.get_variety() + ", " +
           noodle_r.get_style() + ", " +
           noodle_r.get_country() + ", " +
           std::to_string(noodle_r.get_stars()) + ", " +
           noodle_r.get_top_ten();
}

void display_noodle_reviews(void* nr_list)
{
    // cast to linked list and then take head
    Node* current = ((LinkedList *)nr_list)->get_head();
    while (current != nullptr)
    {
        std::cout << assemble_noodle_review(*current->get_data()) << std::endl;
        current = current->get_next_node();
    }
}

NoodleReview::NoodleReview(int reviewNum, std::string brand, std::string variety, std::string style, std::string country, double stars, std::string topTen)
{
    this->reviewNum = reviewNum;
    this->brand = brand;
    this->variety = variety;
    this->style = style;
    this->country = country;
    this->stars = stars;
    this->topTen = topTen;
}

int NoodleReview::get_review_number()
{
    return reviewNum;
}

std::string NoodleReview::get_brand()
{
    return brand;
}

std::string NoodleReview::get_variety()
{
    return variety;
}

std::string NoodleReview::get_style()
{
    return style;
}

std::string NoodleReview::get_country()
{
    return country;
}

double NoodleReview::get_stars()
{
    return stars;
}

std::string NoodleReview::get_top_ten()
{
    return topTen;
}