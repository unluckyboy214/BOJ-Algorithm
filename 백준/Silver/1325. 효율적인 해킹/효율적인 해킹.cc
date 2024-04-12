#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<int>> com;
vector<int> Visited;
vector<int> hacking;
queue<int> q;

int bfs(int start) {
	// bfs시마다 방문 기록 초기화
	fill(Visited.begin(), Visited.end(), 0);
	q.push(start);
	Visited[start] = 1;

	int count = 1;
	while (!q.empty()){
		int now = q.front();
		q.pop();

		for (int i = 0; i < com[now].size(); i++) {
			int next = com[now][i];
			if (!Visited[next]) {
				Visited[next] = 1;
				q.push(next);
				count++;
			}
		}
	}

	return count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, A, B;
	cin >> N >> M;

	com.resize(N + 1);
	Visited.resize(N + 1);
	hacking.resize(N + 1);

	int max_hacking = 0;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		com[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		hacking[i] = bfs(i);
		max_hacking = max(hacking[i], max_hacking);
	}

	for (int i = 1; i <= N; i++) {
		if (hacking[i] == max_hacking) {
			cout << i << " ";
		}
	}

	return 0;
}