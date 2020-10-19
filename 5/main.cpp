#include <cstdlib>
#include <iostream>
#include <string>

/* Function that replaces given character in a string with
next character that's different than given one */
std::string stringswapping(std::string str, int position)
{
    for (int i = position; i < str.length(); ++i) {
            if (str[position] != str[i]) {
                std::swap(str[position], str[i]);
                return str;
            }
    }
}

int main()
{
    //Initialization of string
    std::string str;
    std::cin >> str;

    /* Check if two characters in string are the same
    if yes - then call stringswapping function */
    for (int i = 0; i < str.length() - 1; ++i) {
        if (str[i] == str[i + 1])
            str = stringswapping(str, (i + 1));
    }

    /* Check if any of the characters that are same are
    close together, if yes then this task is impossible
    and print "None" */
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == str[i + 1]) {
            std::cout << "None\n";
            return EXIT_SUCCESS;
        }
    }

    /* If there are no same characters next to each other
    in string print that string out */
    std::cout << str << "\n";

    return EXIT_SUCCESS;
}
