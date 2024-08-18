#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long n;
	cin >> n;

	long long dp[117] = { 0, };
	dp[1] = dp[2] = dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}

	cout << dp[n];

	return 0;
}