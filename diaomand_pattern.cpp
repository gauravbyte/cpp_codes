#include <iostream>

int main() {
    int rows;
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows - i; ++j) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; ++k) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    for (int i = rows - 1; i >= 1; --i) {
        for (int j = 1; j <= rows - i; ++j) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; ++k) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}
