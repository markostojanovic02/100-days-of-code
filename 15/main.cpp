#include <bits/stdc++.h>

typedef long long int ll;

//Function that prints out all prefixes
void solve(std::string str[], ll N)
{
    std::string prefix[N] = "";
    ll k;
    bool found;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            k = 1;
            found = false;
            //If two words are same, they have no prefixes
            if (str[i] == str[j]) {
                prefix[i] = str[i];
                prefix[j] = str[j];
                found = true;
            }
            //Searching for shortest unique prefix between two words
            while (!found) {
                /* After we've found shortest unique prefix between two words
                we check if length of it is longer than previous one */
                if (str[i].substr(0, k) != str[j].substr(0, k)) {
                    if (k > prefix[i].length())
                        prefix[i] = str[i].substr(0, k);
                    if (k > prefix[j].length())
                        prefix[j] = str[j].substr(0, k);

                    found = true;
                } else {
                    ++k;
                }
            }
        }
    }

    //Printing out all prefixes
    std::cout << "\n";
    for (int i = 0; i < N; ++i) {
        std::cout << prefix[i] << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    ll N;
    std::cin >> N;

    std::string listOfWords[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> listOfWords[i];
    }

    //Calling our function
    solve(listOfWords, N);
    return 0;
}
