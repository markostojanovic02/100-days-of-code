#include <cmath>
#include <cstdlib>
#include <iostream>

//Function that checks if 2 intervals overlap
bool overlap(int FirstStart, int FirstEnd, int SecondStart, int SecondEnd)
{
    //First case: one interval starts inside other
    if (SecondStart > FirstStart && SecondStart < FirstEnd)
        return true;
    //Second case: one interval end inside other
    if (SecondEnd > FirstStart && SecondEnd < FirstEnd)
        return true;
    //Third case: if one interval starts before and ends after other one
    if (SecondStart < FirstStart && SecondEnd > FirstEnd)
        return true;

    return false;
}

int main()
{
    //Initialization and input of intervals
    int number_of_intervals;
    std::cin >> number_of_intervals;

    int start_of_interval[number_of_intervals];
    int end_of_interval[number_of_intervals];
    for (int i = 0; i < number_of_intervals; ++i) {
        std::cin >> start_of_interval[i];
        std::cin >> end_of_interval[i];
    }

    //Sorting our intervals based on their end value
    for (int i = 0; i < number_of_intervals; ++i) {
        for (int j = i + 1; j < number_of_intervals; ++j) {
            if (end_of_interval[j] > end_of_interval[i]) {
                std::swap(start_of_interval[i], start_of_interval[j]);
                std::swap(end_of_interval[i], end_of_interval[j]);
            }
        }
    }

    int OverlapCounter, points[number_of_intervals], highest, counter = 0, highestIndex;
    while(true) {
        //Restarting points
        for (int i = 0; i < number_of_intervals; ++i) {
            points[i] = 0;
        }

        //Adding points for every interval based on how many intervals it overlaps with
        OverlapCounter = 0;
        for (int i = 0; i < number_of_intervals; ++i) {
            for (int j = i + 1; j < number_of_intervals; ++j)
            if (overlap(start_of_interval[i], end_of_interval[i], start_of_interval[j], end_of_interval[j])) {
                ++points[i];
                ++points[j];
                ++OverlapCounter;
            }
        }

        //If no overlapping intervals print out the counter
        if (OverlapCounter == 0) {
            std::cout << counter << "\n";
            return EXIT_SUCCESS;
        }

        //Finding out who overlaps with the most
        highest = 0;
        highestIndex = 0;
        for (int i = 0; i < number_of_intervals; ++i) {
            if (points[i] > highest) {
                highest = points[i];
                highestIndex = i;
            }
        }

        //Delete interval that overlaps with the most (make it's start and end value '0')
        start_of_interval[highestIndex] = 0;
        end_of_interval[highestIndex] = 0;
        ++counter;
    }
}
