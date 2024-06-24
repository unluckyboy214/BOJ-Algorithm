#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int N;
	string S;
	int sum = 0;

	cin >> N;
	cin >> S;

	for (auto& x : S) {
		sum += (x - '0');
	}

	cout << sum;

	return 0;
}