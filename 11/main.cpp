#include <cmath>
#include <iostream>

int main()
{
    //Initialization and input
    int N;
    std::cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }

    //Original list
    std::cout << "Original list: ";
    for (int i = 0; i < N; ++i) {
        if (i != 0)
            std::cout << " -> ";
        std::cout << arr[i];
    }

    /* Since there's specific way output needs to be,
    we'll first swap first two elements and then
    all the other ones */
    //Swapping first two members in our list
    std::swap(arr[0], arr[1]);

    //Swapping all other members in our list
    int m = 0, i = 2, j = N - 1;
    while (m != ((N - 1)/ 2)) {
            std::cout << "\nSwapping " << arr[i] << " - " << arr[j];
            std::swap(arr[i], arr[j]);
            --j;
            ++i;
        ++m;
    }

    //Printing new list
    std::cout << "\nNew list: ";
    for (int i = 0; i < N; ++i) {
        if (i != 0)
            std::cout << " -> ";
        std::cout << arr[i];
    }
}
