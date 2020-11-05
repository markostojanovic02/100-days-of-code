#include <bits/stdc++.h>

typedef long long int ll;
int max = 1e7;

//Function that returns wanted difference
int solve(std::string s1, std::string s2, std::string str)
{
    //Mapping positions off all letters in sentence
    int counter = 0, prev = 0;
    std::map<std::string, std::vector<int>> pos;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            ++counter;
            pos[str.substr(prev, i - prev)].push_back(counter);
            prev = i + 1;
        }
    }
    pos[str.substr(prev, str.length() - prev)].push_back(counter + 1);

    //Placing all positions of first word in special vector for it
    std::vector<int> v1;
    for (auto i : pos) {
        if (i.first == s1) {
            for (auto i2 : i.second) {
                v1.push_back(i2);
            }
        }
    }
    //Placing all positions of second word in special vector for it
    std::vector<int> v2;
    for (auto i : pos) {
        if (i.first == s2) {
            for (auto i2 : i.second) {
                v2.push_back(i2);
            }
        }
    }

    //Calculating smallest difference in words
    int smallestDifference = max;
    for (int i = 0; i < v2.size(); ++i) {
        for (int j = 0; j < v1.size(); ++j) {
            if (v2[i] - v1[j] > 0 && v2[i] - v2[j] < smallestDifference)
                smallestDifference = v2[i] - v1[j];
        }
    }

    //Returning it
    return smallestDifference - 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    std::string str;
    getline(std::cin, str);

    std::string s1, s2;
    std::cin >> s1 >> s2;

    //Printing result
    int result = solve(s1, s2, str);
    if (result == 9999999) {
        std::cout << "no result\n";
    } else {
        std::cout << result << "\n";
    }
    return 0;
}
