#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 987654321

using namespace std;

int N, M;
int a, b, c;

typedef long long ll;
typedef pair<ll, ll> Edge;

vector<vector<Edge>> graph;

ll Prim() {
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<ll> cost(N + 1, INF);
    vector<bool> visit(N + 1, false);

    ll ans = 0;

    int start_vertex = -1;
    for (int i = 1; i <= N; ++i) {
        if (!graph[i].empty()) {
            start_vertex = i;
            break;
        }
    }

    if (start_vertex == -1) {
        return -1;
    }

    pq.push(make_pair(0, start_vertex));
    cost[start_vertex] = 0;

    while (!pq.empty()) {
        Edge cur = pq.top();
        pq.pop();
        int u = cur.second;
        ll cur_cost = cur.first;

        if (visit[u]) continue;

        visit[u] = true;
        ans += cur_cost;

        for (auto& x : graph[u]) {
            int v = x.second;
            ll weight = x.first;
            if (cost[v] > weight && !visit[v]) {
                cost[v] = weight;
                pq.push(make_pair(weight, v));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!visit[i]) return -1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll sum = 0;
    cin >> N >> M;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
        sum += c;
    }

    ll mst = Prim();

    if (mst == -1) {
        cout << -1 << endl;
    }
    else {
        cout << sum - mst << endl;
    }

    return 0;
}
