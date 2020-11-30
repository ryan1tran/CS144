#include "IoRunner.h"
#include "LinkedList.h"

int main()
{
    const std::string DATA_FILE_NAME_IN = "ramen-ratings.csv";
    const std::string DATA_FILE_NAME_OUT = "reviews.csv";
    LinkedList reviews;

    IoRunner io;
    reviews = io.read_from_file(DATA_FILE_NAME_IN);

    display_noodle_reviews(&reviews);

    io.write_to_file(DATA_FILE_NAME_OUT, reviews);

    return 0;
}
