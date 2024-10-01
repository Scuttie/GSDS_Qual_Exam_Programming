#include <iostream>
using namespace std;

void swap(char &x, char &y) {
    char temp = x;
    x = y;
    y = temp;
}

void permute(string &s, int l, int r) {
    if (l == r) {
        cout << s << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(s[l], s[i]);  // Swap
            permute(s, l + 1, r);
            swap(s[l], s[i]);  // Backtrack
        }
    }
}

int main() {
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n - 1);
    return 0;
}
