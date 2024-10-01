#include <iostream>
using namespace std;

bool is_palindrome(string &s, int start, int end) {
    if (start >= end)
        return true;
    if (s[start] != s[end])
        return false;
    return is_palindrome(s, start + 1, end - 1);
}

int main() {
    string str = "madam";
    cout << is_palindrome(str, 0, str.size() - 1) << endl;  // Output: 1
    return 0;
}
