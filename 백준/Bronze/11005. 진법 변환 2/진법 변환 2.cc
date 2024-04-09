#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, B;

	cin >> N >> B;
	string res;

	while (N > 0) {
		int tmp = N % B;
		if (0 <= tmp && tmp <= 9) res += (tmp + '0');
		else res += (tmp - 10 + 'A');
		N /= B;
	}
	for (int i = res.length() - 1; i >= 0; i--) {
		cout << res[i];
	}


	return 0;
}