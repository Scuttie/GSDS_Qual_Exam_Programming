#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split_using_substr(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    
    tokens.push_back(str.substr(start));  // 마지막 남은 부분 추가
    
    return tokens;
}

std::vector<std::string> split_using_sstream(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);
    
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

int main() {
    std::string text = "one:two:three:four";
    std::vector<std::string> result = split(text, ':');
    
    for (const auto& s : result) {
        std::cout << s << std::endl;
    }
    
    return 0;
}

