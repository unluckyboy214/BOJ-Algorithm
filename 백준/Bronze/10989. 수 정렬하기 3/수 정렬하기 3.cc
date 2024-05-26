#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;

	cin >> N;

	vector<int> CountArr(10001,0);

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		CountArr[x]++;
	}

	for (int i = 0; i<  CountArr.size(); i++) {
		while (CountArr[i] > 0) {
			cout << i << "\n";
			CountArr[i]--;
		}
	}
	return 0;
}