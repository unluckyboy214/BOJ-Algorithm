#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, cnt;
	string book;
	map<string, int> sell;

	cin >> N;
	while (N--) {
		cin >> book;
		sell[book]++;
	}
	for (auto& i : sell) {
		cnt = max(cnt, i.second);
	}
	for (auto& i : sell) {
		if (i.second == cnt) {
			cout << i.first;
			return 0;
		}
	}
}