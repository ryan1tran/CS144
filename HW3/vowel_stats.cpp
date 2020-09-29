#include "vowel_stats.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

VowelStats::VowelStats()
{
    time_us_count_vector = 0;
    time_us_count_array = 0;
    time_us_bubble_vector = 0;
    time_us_bubble_array = 0;
    time_us_quick_vector = 0;
    time_us_quick_array = 0;
    wordCount = 0;
    defaultTest = {"Hello", "friends,", "how", "is", "your", "day?", "Mine", "has", "been", "quite",
                   "wonderful", "so", "far!", "Let's", "go", "out", "for", "some", "dim", "sum!"};
}

void VowelStats::display_stats()
{
    std::cout << "<<< String Vector Stats (word count = " << wordCount << ") >>>" << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < SIZE; i++)
    {
        switch (vowelCountVectorOrder[i])
        {
            case 0:
                std::cout << "a: " << vowelSorted[i];
                break;
            case 1:
                std::cout << "e: " << vowelSorted[i];
                break;
            case 2:
                std::cout << "i: " << vowelSorted[i];
                break;
            case 3:
                std::cout << "o: " << vowelSorted[i];
                break;
            case 4:
                std::cout << "u: " << vowelSorted[i];
                break;
            default:
                break;
        }

        if (i != SIZE - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
    std::cout << std::fixed // using 'fixed' to format the seconds to not be in scientific notation
              << "counting: " << (int)time_us_count_vector // casting time_us to int because 'fixed' always causes the value to be x.000000, so truncating unnecessary 0's
              << " nanoseconds, " << (time_us_count_vector / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "bubble sort: " << (int)time_us_bubble_vector
              << " nanoseconds, " << (time_us_bubble_vector / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "quick sort: " << (int)time_us_quick_vector
              << " nanoseconds, " << (time_us_quick_vector / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "counting+bubblesort: " << (int)(time_us_count_vector + time_us_bubble_vector)
              << " nanoseconds, " << ((time_us_count_vector + time_us_bubble_vector) / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "counting+quicksort: " << (int)(time_us_count_vector + time_us_quick_vector)
              << " nanoseconds, : " << ((time_us_count_vector + time_us_quick_vector) / 1000.0) << " microseconds" << std::endl << std::endl;

    std::cout << "<<< String Array Stats (word count = " << wordCount << ") >>>" << std::endl;
    std::cout << "[ ";
    for (int i = 0; i < SIZE; i++)
    {
        switch (vowelCountArrayOrder[i])
        {
            case 0:
                std::cout << "a: " << vowelSorted[i];
                break;
            case 1:
                std::cout << "e: " << vowelSorted[i];
                break;
            case 2:
                std::cout << "i: " << vowelSorted[i];
                break;
            case 3:
                std::cout << "o: " << vowelSorted[i];
                break;
            case 4:
                std::cout << "u: " << vowelSorted[i];
                break;
            default:
                break;
        }

        if (i != SIZE - 1)
            std::cout << ", ";
    }
    std::cout << " ]" << std::endl;
    std::cout << std::fixed
              << "counting: " << (int)time_us_count_array
              << " nanoseconds, " << (time_us_count_array / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "bubble sort: " << (int)time_us_bubble_array
              << " nanoseconds, " << (time_us_bubble_array / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "quick sort: " << (int)time_us_quick_array
              << " nanoseconds, " << (time_us_quick_array / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "counting+bubblesort: " << (int)(time_us_count_array + time_us_bubble_array)
              << " nanoseconds, " << ((time_us_count_array + time_us_bubble_array) / 1000.0) << " microseconds" << std::endl;
    std::cout << std::fixed
              << "counting+quicksort: " << (int)(time_us_count_array + time_us_quick_array)
              << " nanoseconds, : " << ((time_us_count_array + time_us_quick_array) / 1000.0) << " microseconds" << std::endl << std::endl;
}

void VowelStats::run_tests(std::vector<std::string> test_list)
{
    if (test_list.empty())
    {
        wordCount = 20;

        get_vector_stats(defaultTest);
        bubblesort(true);
        quicksort(true);

        std::string array_test_list[20]; // fix this

        for (int i = 0; i < wordCount; i++)
            array_test_list[i] = defaultTest.at(i);

        get_array_stats(array_test_list, wordCount);
        bubblesort(false);
        quicksort(false);
    }else
    {
        wordCount = test_list.size();

        get_vector_stats(test_list);
        bubblesort(true);
        quicksort(true);

        int vectSize = test_list.size();
        std::string * array_test_list;
        array_test_list = new std::string[vectSize];

        for (int i = 0; i < vectSize; i++)
            array_test_list[i] = test_list.at(i);

        get_array_stats(array_test_list, vectSize);
        bubblesort(false);
        quicksort(false);
    }
}

void VowelStats::get_vector_stats(std::vector<std::string> vect)
{
    std::fill_n(vowelCountVector, 5, 0); // resets vowelCount array to all 0's
    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    for (int i = 0; i < vect.size(); i++)
    {
        std::string word = vect.at(i);
        for (char c : word)
            vowelCounter(vowelCountVector, c);
    }

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us_count_vector = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

void VowelStats::get_array_stats(std::string arr[], int arr_length)
{
    std::fill_n(vowelCountArray, 5, 0); // resets vowelCount array to all 0's
    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    for (int i = 0; i < arr_length; i++)
    {
        std::string word = arr[i];
        for (char c : word)
            vowelCounter(vowelCountArray, c);
    }

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us_count_array = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
}

void VowelStats::bubblesort(bool is_for_vector)
{
    int vowelCount[SIZE];
    int vowelCountOrder[SIZE] = {0, 1, 2, 3, 4};
    double time_us;

    if (is_for_vector)
        std::copy(std::begin(vowelCountVector), std::end(vowelCountVector), std::begin(vowelCount));
    else
        std::copy(std::begin(vowelCountArray), std::end(vowelCountArray), std::begin(vowelCount));

    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    bool swapped;
    for (int i = 0; i < SIZE - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < SIZE - i - 1; j++)
        {
            if (vowelCount[j] < vowelCount[j + 1])
            {
                swap(&vowelCount[j], &vowelCount[j+1]);
                swap(&vowelCountOrder[j], &vowelCountOrder[j+1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

    if (is_for_vector)
    {
        time_us_bubble_vector = time_us;
        std::copy(std::begin(vowelCount), std::end(vowelCount), std::begin(vowelSorted));
        std::copy(std::begin(vowelCountOrder), std::end(vowelCountOrder), std::begin(vowelCountVectorOrder));
    }else
    {
        time_us_bubble_array = time_us;
        std::copy(std::begin(vowelCount), std::end(vowelCount), std::begin(vowelSorted));
        std::copy(std::begin(vowelCountOrder), std::end(vowelCountOrder), std::begin(vowelCountArrayOrder));
    }
}

void VowelStats::quicksort(bool is_for_vector)
{
    int vowelCount[SIZE];
    int vowelCountOrder[SIZE] = {0, 1, 2, 3, 4};
    double time_us;

    if (is_for_vector)
        std::copy(std::begin(vowelCountVector), std::end(vowelCountVector), std::begin(vowelCount));
    else
        std::copy(std::begin(vowelCountArray), std::end(vowelCountArray), std::begin(vowelCount));

    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    quickSortHelper(vowelCount, 0, SIZE - 1, vowelCountOrder);

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

    if (is_for_vector)
    {
        time_us_quick_vector = time_us;
        std::copy(std::begin(vowelCount), std::end(vowelCount), std::begin(vowelSorted));
        std::copy(std::begin(vowelCountOrder), std::end(vowelCountOrder), std::begin(vowelCountVectorOrder));
    }else
    {
        time_us_quick_array = time_us;
        std::copy(std::begin(vowelCount), std::end(vowelCount), std::begin(vowelSorted));
        std::copy(std::begin(vowelCountOrder), std::end(vowelCountOrder), std::begin(vowelCountArrayOrder));
    }
}

// HELPER FUNCTIONS BELOW

void VowelStats::vowelCounter(int vowelCount[], char letter) // counts vowels
{
    switch(letter)
    {
        case 'a': case 'A':
            vowelCount[0]++;
            break;
        case 'e': case 'E':
            vowelCount[1]++;
            break;
        case 'i': case 'I':
            vowelCount[2]++;
            break;
        case 'o': case 'O':
            vowelCount[3]++;
            break;
        case 'u': case 'U':
            vowelCount[4]++;
            break;
        default:
            break;
    }
}

void VowelStats::swap(int* x, int* y) // swaps values for sorting algorithms
{
    int t = *x;
    *x = *y;
    *y = t;
}

int VowelStats::partition(int arr[], int low, int high, int vowelCountOrder[]) // partitions array for quick sort
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
        if (arr[j] > pivot)
        {
            swap(&arr[++i], &arr[j]);
            swap(&vowelCountOrder[i], &vowelCountOrder[j]);
        }

    swap(&arr[i+1], &arr[high]);
    swap(&vowelCountOrder[i+1], &vowelCountOrder[high]);
    return (i + 1);
}

void VowelStats::quickSortHelper(int vowelCount[], int low, int high, int vowelCountOrder[]) // recursive function for quick sort
{
    if (low < high)
    {
        int pivot = partition(vowelCount, low, high, vowelCountOrder);

        quickSortHelper(vowelCount, low, pivot - 1, vowelCountOrder);
        quickSortHelper(vowelCount, pivot + 1, high, vowelCountOrder);
    }
}
