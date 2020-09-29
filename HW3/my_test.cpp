#include "vowel_stats.cpp"
#include "vowel_stats.h"
#include <iostream>

int main()
{
    VowelStats vs;

    std::vector<std::string> blankTest;
    std::cout << "{ Case #1: Empty vector input }" << std::endl;
    vs.run_tests(blankTest);
    vs.display_stats();

    std::vector<std::string> filledTest = {"Once", "upon", "a", "time", "there", "was", "a", "lovely", "princess.",
                                           "But", "she", "had", "an", "enchantment", "upon", "her", "of", "a", "fearful", "sort",
                                           "which", "could", "only", "be", "broken", "by", "love's", "first", "kiss."};
    std::cout << "{ Case #2: Filled vector input }" << std::endl;
    vs.run_tests(filledTest);
    vs.display_stats();

    return 0;
}
