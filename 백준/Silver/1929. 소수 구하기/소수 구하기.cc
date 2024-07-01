#include <iostream>
#include <vector>

using namespace std;

void Eratos(int M, int N) {
	vector<bool> v(N + 1, 1);

	for (int i = 2; i * i <= N; i++) {
		if (v[i]) {
			for (int k = i * i; k <= N; k += i) {
				v[k] = 0;
			}
		}
	}

	for (int i = 2; i < v.size(); i++) {
		if (v[i] && i>=M) cout << i << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int M, N;
	cin >> M >> N;
	Eratos(M, N);

	return 0;
}