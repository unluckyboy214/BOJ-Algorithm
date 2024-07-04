#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	vector<int> vec(N);
	
	for (int i = 0; i < N; i++) {
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (auto& x : vec) {
		cout << x << "\n";
	}

	return 0;
}