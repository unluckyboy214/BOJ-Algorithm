#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int dp[1516][3] = { 0 };

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 0;

	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	cout << dp[N][0];

	return 0;
}