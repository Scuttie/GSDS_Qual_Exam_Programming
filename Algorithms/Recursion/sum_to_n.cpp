#include <iostream>
using namespace std;

int sum_to_n(int n) {
    if (n <= 1)
        return n;
    return n + sum_to_n(n - 1);
}

int main() {
    cout << sum_to_n(5) << endl;  // Output: 15
    return 0;
}
