#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isTree(int N, int M, vector<pair<int, int>>& edges) {
	//트리는 항상 N-1개의 간선 가짐
	if (M != N - 1) return false;

	vector<vector<int>> adj(N + 1); //인접리스트
	vector<bool> visited(N + 1, false); // 방문 여부 기록

	//간선 정보를 통해 인접리스트 구현
	for (auto& edge : edges) {
		adj[edge.first].push_back(edge.second);
		adj[edge.second].push_back(edge.first);
	}

	//BFS로 그래프 연결 확인
	queue<int> q;
	q.push(1); // 1번 노드 시작
	visited[1] = true;

	int visitedCount = 1; // 방문한 노드수

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int neighbor : adj[node]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
				visitedCount++;
			}
		}
	}

	// 모든 노드가 방문이 안되면 트리가 아님
	if (visitedCount != N) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N ,M; //노드, 엣지 수
		cin >> N >> M;

		vector<pair<int, int>> edges(M);

		//간선 정보 입력
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			edges[i] = { A,B };
		}

		//그래프가 트리인지 확인
		if (isTree(N, M, edges)) {
			cout << "tree" << "\n";
		}
		else {
			cout << "graph" << "\n";
		}

	}

	return 0;
}