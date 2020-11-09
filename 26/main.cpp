#include <bits/stdc++.h>

typedef long long int ll;

int main()
{
    std::string str;
    getline(std::cin, str);

    ll counter = 0, counter2 = 0;
    for (int i = 0; i < str.length(); ++i) {
        //If ')' starts first it's not balanced
        if (counter  + counter2 < 0) {
            std::cout << "not balanced\n";
            return 0;
        }

        if (str[i] == '(')
            ++counter;
        if (str[i] == ')')
            --counter;
        if (str[i] == '*')
            ++counter2;
    }
    //If there's more '(' or ')'
    if (counter != 0 && counter - counter2 != 0) {
        std::cout << "not balanced\n";
    } else {
        //If everything's cool
        std::cout << "balanced\n";
    }
    return 0;
}
