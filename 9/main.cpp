#include <bits/stdc++.h>
#include <iostream>

int longestSubarray(int arr[], int N)
{
    std::map<int, int> pos;
    int answer = 0, j = 0;
    for(int i = 0; i < N; ++i)
    {
        j = std::max(j, pos[arr[i]]);
        pos[arr[i]] = i + 1;
        answer = std::max(answer, i - j + 1);
    }

    return answer;
}

int main()
{
    int N;
    std::cin >> N;

    int arr[N];
    for(int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::cout << longestSubarray(arr, N) << "\n";
    return EXIT_SUCCESS;
}
