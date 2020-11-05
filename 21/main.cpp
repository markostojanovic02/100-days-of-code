#include <bits/stdc++.h>

typedef long long int ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    unsigned int N;
    std::cin >> N;

    std::string newN;
    newN = std::to_string(N);
    for (int i = 0; i < 8; i+=2) {
        std::swap(newN[i], newN[i + 1]);
    }

    std::cout << newN;
    return 0;
}
