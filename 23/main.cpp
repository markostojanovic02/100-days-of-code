#include <bits/stdc++.h>

typedef long long int ll;

//Function that returns if it's possible or not
bool solve(std::string str)
{
    //Mapping number of each letter repetitions
    std::map<char, int> pos;
    for (int i = 0; i < str.length(); ++i) {
        ++pos[str[i]];
    }

    //Checking how many letters are repeated odd number of times
    int odd = 0;
    for (auto i : pos) {
        if (i.second % 2 != 0)
            ++odd;
    }

    /* For word to be possible palindrome it has to have
        all even numbers or at most one odd number */
    if (odd > 1)
        return false;
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    std::string str;
    std::cin >> str;

    //Output
    if (solve(str)) {
        std::cout << "true\n";
    } else {
        std::cout << "false\n";
    }
    return 0;
}
