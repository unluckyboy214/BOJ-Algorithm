#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int N;

	cin >> N;

	long long result = 0;
	for (int i = 1; i <= N; i++) {
		result += (N / i) * i;
	}
	cout << result;

	return 0;
}