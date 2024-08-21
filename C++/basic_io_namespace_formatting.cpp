#include <iostream>
#include <string>
#include <iomanip>
#include <limits> // For numeric_limits

using namespace std;

// Namespace example
namespace myNamespace {
    int a, b;

    void setValues(int newValueA, int newValueB) {
        a = newValueA;
        b = newValueB;
    }
}

// Global namespace definitions
namespace first {
    int x = 5;
}

namespace second {
    double x = 3.1416;
}

namespace third = first;

// Function to demonstrate basic input and output
void basicInputOutput() {
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (!(cin)) { // Check for input error
        cerr << "That was not a number!" << endl;
        cin.clear(); // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
    } else {
        cout << "You entered: " << number << endl;
    }
}

// Function to demonstrate namespace usage
void namespaceExample() {
    myNamespace::a = 5;
    myNamespace::b = 3;
    myNamespace::setValues(10, 20);
    cout << "Namespace myNamespace values: a = " << myNamespace::a << ", b = " << myNamespace::b << endl;

    cout << "Namespace first::x = " << first::x << endl;
    cout << "Namespace second::x = " << second::x << endl;

    cout << "Namespace third::x (alias of first::x) = " << third::x << endl;
}

// Function to demonstrate reading a full line of input
void readFullLine() {
    string myStr;
    cout << "Enter a full sentence: ";
    cin.ignore(); // To ignore the leftover newline character in the input buffer
    getline(cin, myStr);
    cout << "You entered: " << myStr << endl;
}

// Function to demonstrate output formatting
void formattingExample() {
    double pi = 3.14159265;
    cout << "Pi with 2 decimal places (setprecision): " << setprecision(2) << pi << endl;
    cout << "Pi with 2 decimal places (fixed): " << setprecision(2) << fixed << pi << endl;

    double number = 123456789.123456789;
    cout << "Number with 4 significant digits: " << setprecision(4) << number << endl;
    cout << "Number with 4 decimal places (fixed): " << setprecision(4) << fixed << number << endl;

    int number2 = 5;
    cout << "Number padded with zeros (setw and setfill): " << setfill('0') << setw(8) << number2 << endl;
}

// Main function demonstrating all features
int main() {
    cout << "=== Basic Input and Output ===" << endl;
    basicInputOutput();
    cout << endl;

    cout << "=== Namespace Example ===" << endl;
    namespaceExample();
    cout << endl;

    cout << "=== Reading a Full Line ===" << endl;
    readFullLine();
    cout << endl;

    cout << "=== Formatting Example ===" << endl;
    formattingExample();
    cout << endl;

    return 0;
}
