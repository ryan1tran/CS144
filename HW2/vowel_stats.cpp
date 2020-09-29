#include "vowel_stats.h"
#include <vector>
#include <string>
#include <iostream>
#include <chrono>

int vowelCount[5] = {0};
double time_us = 0;

void vowelCounter(char letter)
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

void display_stats()
{
    std::cout << "[ Vowel Statistics ]" << std::endl;
    std::cout << "a: " << vowelCount[0] << std::endl;
    std::cout << "e: " << vowelCount[1] << std::endl;
    std::cout << "i: " << vowelCount[2] << std::endl;
    std::cout << "o: " << vowelCount[3] << std::endl;
    std::cout << "u: " << vowelCount[4] << std::endl;
    std::cout << std::fixed // using 'fixed' to format the seconds to not be in scientific notation
    << "Elapsed time => microseconds: " << (int)time_us // casting time_us to int because 'fixed' always causes the value to be x.000000, so truncating unnecessary 0's
    << "us, in seconds: " << (time_us / 1000000.0) << "s" << std::endl << std::endl;
}

void get_vector_stats(std::vector<std::string> vect)
{
    std::fill_n(vowelCount, 5, 0); // resets vowelCount array to all 0's
    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    for (int i = 0; i < vect.size(); i++)
    {
        std::string word = vect.at(i);
        for (int j = 0; j < word.length(); j++)
            vowelCounter(word[j]);
    }

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "{ Vector }" << std::endl;
    display_stats();
}

void get_array_stats(std::string arr[], int arr_length)
{
    std::fill_n(vowelCount, 5, 0); // resets vowelCount array to all 0's
    std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();

    for (int i = 0; i < arr_length; i++)
    {
        std::string word = arr[i];
        for (int j = 0; j < word.length(); j++)
            vowelCounter(word[j]);
    }

    std::chrono::time_point<std::chrono::system_clock> end_time = std::chrono::system_clock::now();
    time_us = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

    std::cout << "{ Array }" << std::endl;
    display_stats();
}