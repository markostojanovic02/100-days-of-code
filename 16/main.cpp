#include <bits/stdc++.h>

typedef long long int ll;

//Function that checks if one word is anagram of the other one
bool anagram(std::string w, std::string s)
{
    //Sorting first word
    for (int i = 0; i < w.length(); ++i) {
        for (int j = i + 1; j < w.length(); ++j) {
            if (w[j] < w[i])
                std::swap(w[i], w[j]);
        }
    }

    //Sorting second word
    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
            if (s[j] < s[i])
                std::swap(s[i], s[j]);
        }
    }

    //Checking if they're same
    if (w == s)
        return 1;
    return 0;
}

int main()
{
    //Initialization and input
    std::string W, S;
    std::cin >> W >> S;

    //Checking for all possible solutions using function "anagram"
    for (int i = 0; i < S.length(); ++i) {
        if (anagram(W, S.substr(i, W.length())))
            std::cout << i << " ";
    }
}
