#include <bits/stdc++.h>

typedef long long int ll;

//Function that finds greatest common denominator between two numbers
ll GCD(ll n1, ll n2)
{
    if (n1 == 0)
        return n2;
    GCD(n2 % n1, n1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    ll N;
    std::cin >> N;

    ll arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    //Searching for greatest common denominator between two numbers of array
    ll gcd;
    for (int i = 0; i < N - 1; ++i) {
        gcd = GCD(arr[i], arr[i + 1]);
    }

    std::cout << gcd << "\n";
    return 0;
}
