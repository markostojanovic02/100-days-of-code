#include <cmath>
#include <cstdlib>
#include <iostream>

int main()
{
    //Initialization and input
    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    /* If first number is smaller than last one that
    means array wasn't rotated */
    if (arr[0] < arr[N - 1]) {
        std::cout << arr[0] << "\n";
        return EXIT_SUCCESS;
    }

    int smallest = arr[0];
    int start = 0, en = N, m;
    //Repeat for log(N) - time restriction
    for (int i = 0; i < log2(N); ++i) {
        /* If the number before center is smaller than last number
         in current array then our smallest number is in first half*/
        m = (en + start) / 2;
        if (arr[m - 1] < arr[en - 1]) {
            en = m;
            //Checking smallest number
            if (arr[m - 1] < smallest)
                smallest = arr[m];
        } else {
            /* If number before center of array is larger than last number
                in current array then smallest number is in second half */
            start = m;
            //Checking smallest number
            if (arr[m] < smallest)
                smallest = arr[m];
        }
    }

    //Printing smallest number
    std::cout << smallest;
}
