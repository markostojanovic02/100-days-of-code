#include <iostream>

//Function that checks if 2 lines intersect
//There are 4 possibilities
bool intersects(int p1, int q1, int p2, int q2)
{
    int firstDifference;
    //1. both numbers are positive
    if (p1 >= 0 && q1 >= 0) {
        firstDifference = q1 - p1;
    } else if (p1 >= 0 && q1 <= 0) {
        //first number is positive and second negative
        firstDifference = q1 - p1;
    } else if (p1 <= 0 && q1 >= 0) {
        //first number is negative and second positive
        firstDifference = p1 - q1;
    } else {
        //both numbers are negative
        firstDifference = -p1 + q2;
    }

    int secondDifference;
    //1. both numbers are positive
    if (p2 >= 0 && q2 >= 0) {
        secondDifference = q2 - p2;
    } else if (p2 >= 0 && q2 <= 0) {
        //first number is positive and second negative
        secondDifference = q2 - p2;
    } else if (p2 <= 0 && q2 >= 0) {
        //first number is negative and second positive
        secondDifference = p2 - q2;
    } else {
        //both numbers are negative
        secondDifference = -p2 + q2;
    }

    /* If both differences are same that lines are
    parallel and they don't intersect */
    if (firstDifference == secondDifference)
        return false;

    return true;
}

int main()
{
    //Initialization and input
    int N;
    std::cin >> N;

    int p[N];
    int q[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> p[i];
        std::cin >> q[i];
    }

    int counter = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (intersects(p[i], q[i], p[j], q[j]))
                ++counter;
        }
    }

    std::cout << counter << "\n";
}
