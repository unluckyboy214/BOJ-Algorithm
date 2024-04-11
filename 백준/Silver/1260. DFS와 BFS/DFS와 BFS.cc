#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
vector<int> v[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	cout << start << " ";
	for (auto& next : v[start]) {
		if (!check[next]) dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (auto& next : v[now]) {
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, V, x, y;
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (auto& list : v) {
		sort(list.begin(), list.end());
	}
	dfs(V);
	cout << "\n";
	memset(check, false, sizeof(check));
	bfs(V);


	return 0;
}