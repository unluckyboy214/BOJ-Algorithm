#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int N;
	cin >> N;
	
	vector<pair<int, string>> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	stable_sort(arr.begin(), arr.end(), compare);

	for (auto& x : arr) {
		cout << x.first << " " << x.second << "\n";
	}

	return 0;
}