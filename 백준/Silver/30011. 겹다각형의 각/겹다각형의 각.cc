#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;
	//vector<int> x(N);
	queue<int> q;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		q.push(x);
	}

	int sum = 0;

	//첫번째 도형
	int now = q.front();
	q.pop();

	while (!q.empty()) {
		if (!q.empty()) {
			sum += (180 * now);
			now = q.front();
			q.pop();
		}
	}
	sum += 180 * (now-2);

	cout << sum;

	return 0;
}