#include <bits/stdc++.h>

//Function that returns largest subarray
int largestSubarray(int arr[], int N)
{
    int maximum = 0, sum = 0, potential_sum = 0, max_num = arr[0];
    //For loop goes to N because O(N) time requirements
    for (int i = 0; i < N; ++i) {
        /* In case all numbers are negative, maximum
            subarray is just one number (largest one),
            so we search for largest number */
        if (arr[i] > max_num)
            max_num = arr[i];

        /* If current number we're looking at is negative
            then we restart sum and potential sum
            (potential sum is sum of all numbers beyond end
             of array (because our array is circular)*/
        if (arr[i] < 0) {
            sum = 0;
            potential_sum = 0;
        } else {
            //Adding current number to the sum
            sum += arr[i];

            //Adjusting potential sum
            if (arr[N - 1 - i] < 0) {
                potential_sum = 0;
            } else {
                potential_sum += arr[N - i - 1];
            }
        }
        /* At the end we add potential sum to our sum (except in case they're same
            (because in that case all numbers in array are positive)) */
        if (i == (N - 1) && sum != potential_sum) {
            sum += potential_sum;
        }

        /* Checking if our current sum is larger
            than current largest sum */
        if (sum > maximum)
            maximum = sum;
    }

    if (max_num < 0) {
        return max_num;
    }

    return maximum;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    //Initialization and input
    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::cout << largestSubarray(arr, N) << "\n";

    return 0;
}


