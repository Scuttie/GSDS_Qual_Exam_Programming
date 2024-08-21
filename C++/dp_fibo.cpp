#include <iostream>
using namespace std;

//피보나치 수열의 값을 저장할 배열
int arr[10001];

//피보나치 수열을 계산하는 함수 by 동적계획법
int fibo(int x) {
	//초기 조건, fibo(0)=0 fibo(1)=1
	if (x <= 1) {
		arr[x] = x;
		return arr[x];
	}
	//만약 이미 값을 구한 경우라면 앞서 구한 값을 사용한다.
	if (arr[x] != 0) {
		return arr[x];
	}
	arr[x] = fibo(x - 1) + fibo(x - 2);
	return arr[x];
}


int main() {
	int T;
	cin >> T;

    for (int i = 0; i < T; i++){
        cout << i << "th: " << fibo(i) << endl;
    }
}