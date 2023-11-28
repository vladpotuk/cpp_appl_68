#include "myFileStats.h"
#include <iostream>

FileStatistics::FileStatistics(const std::string& filename) : filename(filename), charCount(0), lineCount(0), vowelCount(0), consonantCount(0), digitCount(0) {}

void FileStatistics::calculateStatistics() {
    FILE* file;
    if (fopen_s(&file, filename.c_str(), "r") != 0) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        charCount++;

        if (ch == '\n') {
            lineCount++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowelCount++;
            }
            else {
                consonantCount++;
            }
        }
        else if (ch >= '0' && ch <= '9') {
            digitCount++;
        }
    }

    fclose(file);
}

void FileStatistics::displayStatistics() const {
    std::cout << "File: " << filename << std::endl;
    std::cout << "Character count: " << charCount << std::endl;
    std::cout << "Line count: " << lineCount << std::endl;
    std::cout << "Vowel count: " << vowelCount << std::endl;
    std::cout << "Consonant count: " << consonantCount << std::endl;
    std::cout << "Digit count: " << digitCount << std::endl;
}
