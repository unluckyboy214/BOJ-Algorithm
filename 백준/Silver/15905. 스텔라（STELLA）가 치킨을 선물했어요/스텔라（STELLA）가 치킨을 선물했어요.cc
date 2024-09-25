#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 해결 문제 같을때, 패널티 비교
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//참가자 수
	int N;
	cin >> N;

	vector<pair<int, int>> students(N + 1);

	//각 참가자 해결 문제 개수, 패널티 총합
	for (int i = 0; i < N; i++) {
		int sol_cnt, penalty;
		cin >> sol_cnt >> penalty;

		students[i].first = sol_cnt;
		students[i].second = penalty;
	}

	sort(students.begin(), students.end(), compare);

	int fifth = students[4].first;

	int cnt = 0;
	for (int i = 0; i < students.size(); i++) {
		if (i>4 && students[i].first == fifth) cnt++;
	}

	cout << cnt ;

	return 0;
}