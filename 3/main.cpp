#include <cmath>
#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    //Making an array
    int arr[N];
    for(int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    //Signing off all numbers that aren't prime using method given
    int top = ceil(sqrt(N)) - 1;
    for(int i = 2; i < top; ++i) {
        for (int j = i+i; j < N; j += i) {
            arr[j] = 0;
        }
    }

    //Printing out prime numbers
    for (int i = 0; i < N; ++i) {
        if (arr[i] != 0)
            std::cout << arr[i] << " ";
    }
}
