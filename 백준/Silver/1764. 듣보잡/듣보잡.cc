#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	int cnt =0;
	string x;
	map<string, bool> list;
	vector<string> result;

	cin >> N >> M;

	while (N--) {
		cin >> x;
		list.insert(make_pair(x, true));
	}
	while (M--) {
		cin >> x;
		if (list[x] == true) {
			result.push_back(x);
			cnt++;
		}
	}
	cout << cnt << "\n";
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}