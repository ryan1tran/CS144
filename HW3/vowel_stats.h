#ifdef __cplusplus
#ifndef VS_H
#define VS_H

#include <vector>
#include <string>

#define SIZE 5

class VowelStats
{
    public:
        VowelStats();
        void display_stats();
        void run_tests(std::vector<std::string> test_list);

    private:
        double time_us_count_vector;
        double time_us_count_array;
        int vowelCountVector[SIZE] = {0};
        int vowelCountArray[SIZE] = {0};
        int vowelSorted[SIZE] = {0};
        int vowelCountVectorOrder[SIZE] = {0, 1, 2, 3, 4};
        int vowelCountArrayOrder[SIZE] = {0, 1, 2, 3, 4};
        double time_us_bubble_vector;
        double time_us_bubble_array;
        double time_us_quick_vector;
        double time_us_quick_array;
        int wordCount;
        std::vector<std::string> defaultTest;
        void get_vector_stats(std::vector<std::string> vect);
        void get_array_stats(std::string arr[], int arr_length);
        void bubblesort(bool is_for_vector);
        void quicksort(bool is_for_vector);

        // HELPER FUNCTIONS BELOW

        void vowelCounter(int vowelCount[], char letter); // counts vowels
        void swap(int* a, int* b); // swaps values for sorting algorithms
        int partition (int arr[], int low, int high, int vowelCountOrder[]); // partitions array for quick sort
        void quickSortHelper(int vowelCount[], int low, int high, int vowelCountOrder[]); // recursive function for quick sort
};

#endif
#endif