#include <cstdlib>
#include <iostream>

int main()
{
    int number_of_numbers;
    std::cout << "Input number of numbers: ";
    std::cin >> number_of_numbers;

    int number[number_of_numbers];
    std::cout << "Input numbers: ";
    for (int i = 0; i < number_of_numbers; ++i) {
        std::cin >> number[i];
    }

    int k;
    std::cout << "Input number K: ";
    std::cin >> k;

    for (int i = 0; i < number_of_numbers; ++i) {
        for (int j = i + 1; j < number_of_numbers; ++j) {
            if (number[i] + number[j] == k) {
                std::cout << "true\n";
                std::cout << number[i] << " + " << number[j] << " = " << k << "\n";
                return EXIT_SUCCESS;
            }
        }
    }

    std::cout << "false\n";
}
