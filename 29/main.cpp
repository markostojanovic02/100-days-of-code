#include <bits/stdc++.h>

typedef long long int ll;

/* Because pow() returns double I made function that returns long long int
    for base 2(so we can make array out of it) */
ll power(ll n)
{
    ll num = 2;
    for (int i = 1; i < n; ++i) {
        num *= 2;
    }
    return num;
}
/* Function that checks if we change number at certain bit
 will it overlap with another number in our array of strings */
bool canChange(std::string arr[], ll N, std::string str, int j)
{
    if (str[j] == '0') {
        str[j] = '1';
    } else {
        str[j] = '0';
    }
    for (int i = 0; i < N; ++i) {
        if (str == arr[i])
            return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    ll N;
    std::cin >> N;

    //Making all number N-bits and all 0-s
    ll numbers = power(N);
    std::string str[numbers] = "";
    for (int i = 0; i < numbers; ++i) {
        for (int j = 0; j < N; ++j) {
            str[i] += "0";
        }
    }

    int i = 1;
    while (i < numbers) {
        //We start changing j from the end because we read from left to right
        for (int j = N - 1; j >= 0;) {
            if(canChange(str, numbers, str[i], j)) {
                //If certain bit can be changed we change it
                if (str[i].at(j) == '0') {
                    str[i].at(j) = '1';
                } else {
                    str[i].at(j) = '0';
                }
                //Reset i and j and make next number = current one
                ++i;
                //Watching for possible array pointer issue
                if (i == numbers)
                    break;
                j = N - 1;
                str[i] = str[i - 1];
            } else {
                --j;
            }
        }
    }
    //Printing out all the numbers
    for (int i = 0; i < numbers; ++i) {
        std::cout << str[i] << "\n";
    }
    return 0;
}
