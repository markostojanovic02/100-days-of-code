#include <bits/stdc++.h>

typedef long long int ll;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    std::string s1, s2;
    std::cin >> s1 >> s2;
    //Make longer string s1, and shorter s2
    if (s2.length() > s1.length())
        std::swap(s1, s2);

    for (int i = 0; i < s1.length();) {
        for (int j = 0; j < s2.length(); ++j) {
            /* Replace bits in strings, 1 for number that has same one in 2nd string,
                0 for one that doesnt */
            if (s1[i] == s2[j]) {
                s1[i] = '1';
                s2[j] = '1';
                ++i;
                j = 0;
            }
        }
        if (s1[i] != '1')
            s1[i] = '0';
        ++i;
    }
    //Count amount of 0s
    ll counter = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == '0')
            ++counter;
    }
    //Print it out
    std::cout << counter << "\n";
    return 0;
}
