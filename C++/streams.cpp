#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Reading from a file
void readFileOption1(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    std::string line;
    std::cout << "Reading lines from " << filename << ":\n";
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

// Reading numbers from a file
void readFileOption2(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::cout << "Reading numbers from " << filename << ":\n";

    // 파일에서 줄 단위로 읽어옴
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int number;
        
        // 각 줄에서 숫자를 추출하여 출력
        while (ss >> number) {
            std::cout << number << std::endl;
        }
    }

    file.close();
}

// Writing to a file
void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    file << content << std::endl;
    std::cout << "Written to " << filename << ": " << content << std::endl;
    file.close();
}

int main() {
    // Example usage of reading functions
    std::string inputFile = "data.txt";

    // Option 1: Reading lines from a file
    readFileOption1(inputFile);

    // Option 2: Reading numbers from a file
    readFileOption2(inputFile);

    // Example usage of writing function
    std::string outputFile = "output.txt";
    std::string content = "Hello, Data Science!";
    writeFile(outputFile, content);

    return 0;
}
