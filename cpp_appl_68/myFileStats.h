#ifndef MYFILESTATS_H
#define MYFILESTATS_H

#include <string>

class FileStatistics {
public:
    FileStatistics(const std::string& filename);
    void calculateStatistics();
    void displayStatistics() const;

private:
    std::string filename;
    int charCount;
    int lineCount;
    int vowelCount;
    int consonantCount;
    int digitCount;
};

#endif 
