#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#define INF 987654321

using namespace std;

int N, M;
vector<char> gender;
vector<vector<pair<int, int>>> graph;

int Prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> min_edge(N + 1, INF);
    vector<bool> visit(N + 1, false);
    int total_cost = 0;

    for (int i = 1; i <= N; ++i) {
        if (!graph[i].empty()) {
            pq.push({ 0, i });
            min_edge[i] = 0;
            break;
        }
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (visit[u]) continue;
        visit[u] = true;
        total_cost += cost;

        for (auto& edge : graph[u]) {
            int v = edge.second;
            int weight = edge.first;
            if (!visit[v] && min_edge[v] > weight) {
                min_edge[v] = weight;
                pq.push({ weight, v });
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (!visit[i]) return -1;
    }

    return total_cost;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    gender.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> gender[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        if (gender[u] != gender[v]) {
            graph[u].push_back({ d, v });
            graph[v].push_back({ d, u });
        }
    }

    int result = Prim();

    cout << result << endl;

    return 0;
}
