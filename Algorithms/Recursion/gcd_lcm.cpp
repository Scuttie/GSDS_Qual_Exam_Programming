#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    cout << "GCD: " << gcd(48, 18) << endl;   // Output: 6
    cout << "LCM: " << lcm(12, 18) << endl;   // Output: 36
    return 0;
}
