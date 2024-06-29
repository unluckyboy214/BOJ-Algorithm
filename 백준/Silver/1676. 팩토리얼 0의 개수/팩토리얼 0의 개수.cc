#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int N;
	cin >> N;
	int ans = 0;

	for (int i = 5; i <= N; i *= 5) {
		ans += (N / i);
	}

	cout << ans;
	
	return 0;
}