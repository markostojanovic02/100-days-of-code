#include <bits/stdc++.h>

typedef long long int ll;

//Function that prints out longest subarray
void solve(ll arr[], int N)
{
    ll maxStart = 0, maxCombo = 1, start = 0, combo = 1;
    for (int i = 0; i < N - 1; ++i) {
        if (arr[i] % arr[i + 1] == 0 || arr[i + 1] % arr[i] == 0) {
            ++combo;
        } else {
            start = i + 1;
            combo = 1;
        }

        if (combo > maxCombo) {
            maxCombo = combo;
            maxStart = start;
        }
    }

    for (int i = maxStart; i < maxStart+maxCombo; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    int N;
    std::cin >> N;

    ll arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    solve(arr, N);
    return 0;
}
