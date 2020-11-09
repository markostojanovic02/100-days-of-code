#include <bits/stdc++.h>

typedef long long int ll;

int main()
{
    //Initialization and input
    int N;
    std::cin >> N;

    ll arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    ll sum = 0, sum2 = 0;
    for (int i = 0; i < N; ++i) {
        //Calculate sum of all numbers in array
        sum += arr[i];
        /* Calculate sum of all numbers from 1 to N
         (without last one since array us N + 1) */
        if (i != N - 1)
            sum2 += i + 1;
    }
    //Print difference between sums
    std::cout << sum - sum2 << "\n";
}
