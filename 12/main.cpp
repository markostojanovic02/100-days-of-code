#include <array>
#include <cstdlib>
#include <iostream>
#include <string>

//Function that returns number of unique letters in string
int uniqueLetters(std::string str)
{
    int sum = 0;
    bool uniq;
    for (int i = 0; i < str.length(); ++i) {
        uniq = true;
        for (int j = i + 1; j < str.length(); ++j) {
            if (str[i] == str[j])
                uniq = false;
        }
        if (uniq)
            ++sum;
    }

    return sum;
}

//Function that returns positions of unique letters in string
std::array<int, 1000> uniqueLetterPos(std::string str)
{
    bool uniq;
    std::array<int, 1000> pos = {0};
    for (int i = 0; i < str.length(); ++i) {
        uniq = true;
        for (int j = 0; j < str.length(); ++j) {
            /* i != j so same letter doesn't
                compare itself with itself */
            if (i != j) {
                if (str[i] == str[j]) {
                    uniq = false;
                }
            }
        }
        /* Putting position of unique letters in array,
            if letter's aren't unique 0 will be inputted */
        if (uniq)
            pos[i] = i;
    }

    return pos;
}

int main()
{
    //Initialization and input
    std::string s1, s2;
    std::cin >> s1 >> s2;

    /* If two strings don't have same length then it's
        impossible for one-to-one character mapping */
    if (s1.length() != s2.length()) {
        std::cout << "False\n";
        return EXIT_SUCCESS;
    }

    /* If number of unique letters in string is different
        one-to-one character mapping is impossible */
    if (uniqueLetters(s1) != uniqueLetters(s2)) {
        std::cout << "False\n";
        return EXIT_SUCCESS;
    }

    std::array<int, 1000>pos1 = uniqueLetterPos(s1);
    std::array<int, 1000>pos2 = uniqueLetterPos(s2);
    for (int i = 0; i < s1.length(); ++i) {
        /* If positions of unique letters in string are different
            one-to-one character mapping is impossible */
        if (pos1[i] != pos2[i]) {
            std::cout << "False\n";
            return EXIT_SUCCESS;
        }
    }

    /* If all previous checks were passed one-to-one
        character mapping is possible so return true */
    std::cout << "True\n";
    return EXIT_SUCCESS;
}
