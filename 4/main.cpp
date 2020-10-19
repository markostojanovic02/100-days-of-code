#include <cstdlib>
#include <cmath>
#include <iostream>

int main()
{
    //Number of pairs
    int N;
    std::cout << "Number of pairs: ";
    std::cin >> N;

    //Inputing pairs
    std::cout << "Input pairs: ";
    int pairs[2 * N];
    for (int i = 0; i < 2 * N; ++i) {
        std::cin >> pairs[i];
    }

    //Sorting 2 numbers inside one pair
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 1; j < 2 * N; j += 2) {
            if (pairs[j] < pairs[i])
                std::swap(pairs[i], pairs[j]);
        }
    }

    //Sorting pairs
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 2; j < 2 * N; j += 2) {
            if (pairs[j] < pairs[i]) {
                std::swap(pairs[i], pairs[j]);
                std::swap(pairs[i + 1], pairs[j + 1]);
            }
        }
    }

    //Inputing given array
    std::cout << "Input array: ";
    int arr[2 * N];
    for (int i = 0; i < 2* N; ++i) {
        std::cin >> arr[i];
    }

    //Sorting 2 numbers inside one pair in array
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 1; j < 2 * N; j += 2) {
            if (arr[j] < arr[i])
                std::swap(arr[i], arr[j]);
        }
    }

    //Sorting given pairs inside array
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 2; j < 2 * N; j += 2) {
            if (arr[j] < arr[i]) {
                std::swap(arr[i], arr[j]);
                std::swap(arr[i + 1], arr[j + 1]);
            }
        }
    }

    int firstOne = -1, secondOne = -1, counter = 0;
    for (int i = 0; i < 2 * N; i += 2) {
        for (int j = i + 1; j <  2 * N; ++j) {
            /* Check if our current number is pair with next one,
            if not then mark it */
            if (firstOne == -1) {
                if (arr[i] == pairs[i] && arr[j] != pairs[j]) {
                    firstOne = j;
                }
            } else {
            /* After one number is marked check which other number
                isn't next to it's pair and mark it as well */
                if (arr[j] != pairs[j]) {
                    secondOne = j;
                }
            }
            /* After both numbers are marked replace them and increase counter */
            if (firstOne != -1 && secondOne != -1) {
                std::swap(arr[firstOne], arr[secondOne]);
                ++counter;
                //Making it possible for other numbers to switch
                firstOne = -1;
                secondOne = -1;
                /*Need to increase i because otherwise it'll continue swapping
                    first number with other numbers in array */
                i += 2;
            }

            /* Making it possible for other numbers to switch by first sorting
            arrays and then numbers inside them */
            for (int i = 0; i < 2 * N; i += 2) {
                for (int j = i + 2; j < 2 * N; j += 2) {
                    if (arr[j] < arr[i]) {
                        std::swap(arr[i], arr[j]);
                        std::swap(arr[i + 1], arr[j + 1]);
                    }
                }
            }
            for (int i = 0; i < 2 * N; i += 2) {
                for (int j = i + 1; j < 2 * N; j += 2) {
                    if (arr[j] < arr[i])
                        std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    std::cout << "Minimum number of swaps: " << counter << "\n";

    return EXIT_SUCCESS;
}
