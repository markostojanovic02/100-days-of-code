#include <bits/stdc++.h>

typedef long long int ll;

//Function that returns index of element that's repeated most of the time
int amountOfRepeats(ll arr[], int N)
{
    int amount[N] = {0};
    int mostRepeats = 0;
    int index = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i] == arr[j])
                ++amount[i];
        }
        if (amount[i] > mostRepeats)  {
            mostRepeats = amount[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    //Initialization and input
    int N;
    std::cin >> N;

    ll arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    std::cout << arr[amountOfRepeats(arr, N)] << "\n";
    return 0;
}
