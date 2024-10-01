#include <iostream>
#include <cmath>

int count = 0;

void hanoi(int n, int from, int to){
    if (n == 1){
        std::cout << from << " " << to << "\n";
        count++;
    }
    else{
        int aux = 6 - from - to;
        hanoi(n - 1, from, aux);
        std::cout << from << " " << to << "\n";
        count++;
        hanoi(n - 1, aux, to);
    }
}

int main(void){
    int N;
    std::cin >> N;
    std::cout << static_cast<int>(std::pow(2, N) - 1) << std::endl;
    hanoi(N, 1, 3);
}
