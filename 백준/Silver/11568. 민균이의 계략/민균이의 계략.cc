#include <iostream>
#include <vector>

using namespace std;
vector<int> dp;

int Binary_Search(int start, int end, int element) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (element > dp[mid]) start = mid + 1;
		else end = mid;
	}
	return end;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int>card(N);

	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}


	dp.push_back(card[0]);

	for (int i = 1; i < N; i++) {
		if (card[i] > dp.back()) {
			dp.push_back(card[i]);
		}
		else {
			int pos = Binary_Search(0, dp.size() - 1, card[i]);
			dp[pos] = card[i];
		}
	}

	cout << dp.size();

	return 0;
}