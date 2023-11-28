
#include "myFileStats.h"
#include <iostream>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::cin >> filename;

    FileStatistics stats(filename);
    stats.calculateStatistics();
    stats.displayStatistics();

    return 0;
}
