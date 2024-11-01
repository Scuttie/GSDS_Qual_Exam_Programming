int solution(vector<int> &A) {
    if (A.empty()) return 0;  // 배열이 비어 있으면 이익이 없으므로 0 반환

    int max_profit = 0;       // 최대 이익
    int min_price = A[0];     // 최소 가격을 첫 번째 가격으로 초기화

    for (int i = 1; i < A.size(); i++) {
        int current_profit = A[i] - min_price;  // 현재 가격에서 최소 가격을 뺀 값이 이익
        max_profit = max(max_profit, current_profit);  // 최대 이익 갱신
        min_price = min(min_price, A[i]);  // 최소 가격 갱신
    }

    return max_profit;
}
