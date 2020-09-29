#include "vowel_stats.h"
#include <iostream>

int main(void)
{
    // Scenario #1
    std::vector<std::string> vectList1 = {"Today", "will", "be", "a", "great", "day", "and", "many", "more", "to", "come!"};
    std::string arrList1[] = {"Today", "will", "be", "a", "great", "day", "and", "many", "more", "to", "come!"};
    int arrSize1 = sizeof(arrList1)/sizeof(arrList1[0]);

    /*
     * [ Manual Vowel Count ]
     * a: 6
     * e: 4
     * i: 1
     * o: 4
     * u: 0
     */

    std::cout << "<-----------------------SCENARIO #1---------------------->" << std::endl;
    get_vector_stats(vectList1);
    get_array_stats(arrList1, arrSize1);

    //------------------------------------------------------------------------------------------------------------------

    // Scenario #2
    std::vector<std::string> vectList2 = {"words", "are", "full", "of", "vowels"};
    std::string arrList2[] = {"words", "are", "full", "of", "vowels"};
    int arrSize2 = sizeof(arrList2)/sizeof(arrList2[0]);

    /*
     * [ Manual Vowel Count ]
     * a: 1
     * e: 2
     * i: 0
     * o: 3
     * u: 1
     */

    std::cout << "<-----------------------SCENARIO #2---------------------->" << std::endl;
    get_vector_stats(vectList2);
    get_array_stats(arrList2, arrSize2);

    return 0;
}