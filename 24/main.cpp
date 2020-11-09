#include <bits/stdc++.h>

typedef long long int ll;

//Function that prints asked set of numbers
void solve(ll intervals[][2], int N)
{
    //Declaring needed stuff
    std::vector<int> v;
    std::map<int, int> pos;
    int highest, highestKey, counter;
    bool complete = false;
    std::cout << "{";
    while (!complete) {
        //Restoring variables to empty form
       // for (int k = 0; k < 2; ++k) {
        highest = 0, highestKey = 0;
        v.clear();
        pos.clear();
        counter = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                //Storing all common number between two intervals
                if (!(intervals[i][0] == 0 && intervals[i][1] == 0)) {
                    if (intervals[i][1] >= intervals[j][0])
                        v.push_back(intervals[i][1]);
                }
            }
            /* Storing all numbers between two intervals so counting
                each number doesnt start from zero */
            if (intervals[i][0] == 0 && intervals[i][1] == 0) {
                ++counter;
            } else {
                v.push_back(intervals[i][1]);
            }
        }
        //If we've covered all intervals
        if (counter == N) {
            std::cout << "}.\n";
            complete = true;
            break;
        }
        //Store how many times each number is repeated
        for (int i = 0; i < v.size(); ++i) {
            ++pos[v[i]];
        }
        //Find which number's repeated most times
        for (auto i : pos) {
            if (i.second > highest) {
                highest = i.second;
                highestKey = i.first;
            }
        }
        //Print current number out
        if (counter == 0) {
            std::cout << highestKey;
        } else {
            std::cout << ", " << highestKey;
        }
        //Modify our intervals so we know if we've found number that's inside each one
        for (int i = 0; i < N; ++i) {
            if (highestKey >= intervals[i][0] && highestKey <= intervals[i][1]) {
                    intervals[i][0] = 0;
                    intervals[i][1] = 0;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    //Initialization and input
    int N;
    std::cin >> N;

    ll intervals[N][2];
    for (int i = 0; i < N; ++i) {
        std::cin >> intervals[i][0] >> intervals[i][1];
    }
    //Sorting ranges inside intervals
    for (int i = 0; i < N; ++i) {
        if (intervals[i][1] < intervals[i][0])
            std::swap(intervals[i][0], intervals[i][1]);
    }
    //Sort intervals by end value
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (intervals[j][1] < intervals[i][1]) {
                std::swap(intervals[i][0], intervals[j][0]);
                std::swap(intervals[i][1], intervals[j][1]);
            }
        }
    }
    //Calling function to solve it
    solve(intervals, N);
    return 0;
}
