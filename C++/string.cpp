#include <iostream>
#include <string>
#include <sstream>

void stringBasics() {
    std::string str1; // Empty
    std::string str2 = "String2";
    std::string str3("String3");

    // + operator
    std::string firstName = "Data";
    std::string lastName = "Scientist";
    std::string fullName = firstName + " " + lastName;
    std::cout << "Full name using + operator: " << fullName << std::endl; // Output: Data Scientist

    // += operator
    std::string name = "Data";
    name += " Scientist";
    std::cout << "Name using += operator: " << name << std::endl; // Output: Data Scientist

    // append operator
    name = "Data";
    name.append(" Scientist");
    std::cout << "Name using append: " << name << std::endl; // Output: Data Scientist
}

void stringComparison() {
    using namespace std;
    // Comparison
    string str1 = "Apple";
    string str2 = "Banana";
    if (str1 == str2) {
        cout << "str1 is equal to str2" << endl;
    } else if (str1 > str2) {
        cout << "str1 is greater than str2" << endl;
    } else if (str1 < str2) {
        cout << "str1 is less than str2" << endl;
    }

    // compare method
    cout << "Comparing str1 and str2 using compare(): " << endl;
    cout << str1.compare(str2) << endl; // -1
    cout << str2.compare(str1) << endl; // 1
    cout << str1.compare(str1) << endl; // 0
}

void stringFindReplace() {
    using namespace std;

    // find
    string fullName = "Data Science";
    size_t pos = fullName.find("Science");
    if (pos != string::npos) {
        cout << "Found 'Science' at position: " << pos << endl;
    }

    // substr
    string str = "Data Science";
    cout << "Substring of 'Data Science' from index 5 with length 3: " << str.substr(5, 3) << endl; // Output: Sci

    // replace
    string replacedString = str.replace(0, 4, "Bio");
    cout << "Replaced string: " << replacedString << endl; // Output: Bio Science
}

void stringConversion() {
    // std::stoi and std::stod
    std::string number = "42";
    int intNum = std::stoi(number);
    double doubleNum = std::stod(number);

    std::cout << "Integer from string: " << intNum << ", Double from string: " << doubleNum << std::endl;

    // std::to_string
    double doubleValue = 123.456;
    std::string doubleStr = std::to_string(doubleValue);
    std::cout << "String from double: " << doubleStr << std::endl;
}

void stringstreamExample1() {
    // Let's parse a text by commas
    std::stringstream parser("42,3.14,Hello World");
    int intValue;
    double doubleValue;
    std::string strValue;
    char ignoreChar; // Used to ignore the commas
    parser >> intValue >> ignoreChar >> doubleValue >> ignoreChar;
    std::getline(parser, strValue); // Read the remainder
    std::cout << "Parsed values: Integer: " << intValue << ", Double: " << doubleValue << ", String: " << strValue << std::endl;
    // Output: Integer: 42, Double: 3.14, String: Hello World
}

void stringstreamExample2() {
    std::stringstream ss;
    ss << 100;
    ss << 3.14;
    ss << "Hello";
    std::cout << "Stringstream combined output: " << ss.str() << std::endl;
    // Output: 1003.14Hello
}

int main() {
    std::cout << "=== String Basics ===" << std::endl;
    stringBasics();
    std::cout << std::endl;

    std::cout << "=== String Comparison ===" << std::endl;
    stringComparison();
    std::cout << std::endl;

    std::cout << "=== String Find and Replace ===" << std::endl;
    stringFindReplace();
    std::cout << std::endl;

    std::cout << "=== String Conversion ===" << std::endl;
    stringConversion();
    std::cout << std::endl;

    std::cout << "=== Stringstream Example 1 ===" << std::endl;
    stringstreamExample1();
    std::cout << std::endl;

    std::cout << "=== Stringstream Example 2 ===" << std::endl;
    stringstreamExample2();
    std::cout << std::endl;

    return 0;
}
