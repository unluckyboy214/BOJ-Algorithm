#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int T;
	cin >> T;

	int R;
	string S,P;

	for (int i = 0; i < T; i++) {
		cin >> R >> S;

		for (auto& a : S) {
			for (int j = 0; j < R; j++) {
				P.push_back(a);
			}
		}

		cout << P << "\n";
		P.clear();
	}

	return 0;
}