#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, T, P;
	cin >> N;

	vector<int> Size(6);

	for (int i = 0; i < 6; i++) {
		cin >> Size[i];
	}

	cin >> T >> P;

	int cnt = 0;
	for (auto& x : Size) {
		cnt += (x + T - 1) / T;
		
	}

	cout << cnt << "\n" << N / P << " " << N % P;

	return 0;
}