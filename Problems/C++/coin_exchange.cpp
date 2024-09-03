#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// coinChange 함수: 주어진 동전들로 특정 금액을 만들기 위한 최소 동전 수를 계산
int coinChange(vector<int>& coins, int amount) {
    // dp 배열을 amount + 1로 초기화. 이는 주어진 금액을 만들 수 없는 경우를 나타냄.
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;  // 금액이 0일 때는 동전이 필요 없으므로 0으로 설정
    
    // 1부터 amount까지의 금액에 대해 최소 동전 수를 계산
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    // dp[amount]가 초기값(amount + 1)이라면 금액을 만들 수 없는 경우이므로 -1을 반환
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

// main 함수
int main() {
    // 예제 1: coins = {1, 2, 5}, amount = 11
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int result1 = coinChange(coins1, amount1);
    cout << "Input: coins = {1, 2, 5}, amount = 11\n";
    cout << "Output: " << result1 << endl;  // Expected output: 3
    cout << endl;

    // 예제 2: coins = {2}, amount = 3
    vector<int> coins2 = {2};
    int amount2 = 3;
    int result2 = coinChange(coins2, amount2);
    cout << "Input: coins = {2}, amount = 3\n";
    cout << "Output: " << result2 << endl;  // Expected output: -1
    cout << endl;

    // 예제 3: coins = {1}, amount = 0
    vector<int> coins3 = {1};
    int amount3 = 0;
    int result3 = coinChange(coins3, amount3);
    cout << "Input: coins = {1}, amount = 0\n";
    cout << "Output: " << result3 << endl;  // Expected output: 0
    cout << endl;

    return 0;
}
