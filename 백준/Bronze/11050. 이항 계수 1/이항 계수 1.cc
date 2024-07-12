#include <iostream>
#include <vector>

using namespace std;

int Factorial(int x) {
	if (x == 0) return 1;
	return x * Factorial(x - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	int result = Factorial(N) / (Factorial(N - K) * Factorial(K));

	cout << result;

	return 0;
}