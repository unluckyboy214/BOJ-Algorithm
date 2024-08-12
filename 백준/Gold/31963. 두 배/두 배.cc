#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	int N;
	cin >> N;
	vector<int> A(N+1,0);

	// 수열 입력
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 2; i <= N; i++) {
		while (A[i] < A[i - 1]) {
			A[i] *= 2;
			ans++;
		}
	}



	cout << ans;

	return 0;
}