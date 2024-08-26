#include <iostream>
#include <string>

using namespace std;

bool is_blank(std::string::size_type n, std::string const& s)
{
    return (n != std::string::npos);
}

std::string longest_word(std::string input_sentence){
    std::string::size_type n;
    int best_length = 0;
    int best_start_index = 0;

    int current_start_index = 0;
    int current_length = 0;

    for (int i = 0; i <= input_sentence.size(); ++i){
        if (i == input_sentence.size() || input_sentence[i] == ' ') {
            if (current_length > best_length) {
                best_length = current_length;
                best_start_index = current_start_index;
            }
            current_start_index = i + 1;
            current_length = 0;
        } else {
            current_length++;
        }
    }

    return input_sentence.substr(best_start_index, best_length);
}

int main(int argc, char* argv[]){
    std::string line = "computing foundation for data science provides the foundational knowledge on cpp";
    std::cout << longest_word(line) << std::endl;
    return 0;
}
