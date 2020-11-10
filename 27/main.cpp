#include <bits/stdc++.h>

typedef long long int ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string N;
    std::cin >> N;

    for (int i = 0; i < N.length()/2; ++i) {
        std::swap(N[i], N[N.length() - 1 - i]);
    }

    std::cout << N << "\n";
    return 0;
}
