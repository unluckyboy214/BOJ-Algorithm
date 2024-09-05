#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<vector<int>> Tree(n);

	int p, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> p >> c;
		Tree[p].push_back(c);
		Tree[c].push_back(p);
	}

	vector<int> apples(n);

	for (int i = 0; i < n; i++) {
		cin >> apples[i];
	}

	// BFS를 사용해 루트(0번 노드)부터 거리 k 이하의 노드를 탐색
	vector<bool> visited(n, false);
	queue<pair<int, int>> q; // {노드 번호, 루트로부터 거리}
	q.push({ 0, 0 });
	visited[0] = true;
	int apple_count = 0;

	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();

		// 현재 노드에 사과가 있으면 사과 개수를 증가
		if (apples[node] == 1) {
			apple_count++;
		}

		// 현재 거리가 k보다 작은 경우에만 계속 탐색
		if (dist < k) {
			for (int neighbor : Tree[node]) {
				if (!visited[neighbor]) {
					visited[neighbor] = true;
					q.push({ neighbor, dist + 1 });
				}
			}
		}
	}

	// 결과 출력
	cout << apple_count << endl;


	return 0;
}