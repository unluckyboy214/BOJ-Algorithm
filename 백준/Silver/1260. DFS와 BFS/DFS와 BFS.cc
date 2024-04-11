#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<int> a[1001];
bool check[1001];
int N, M, V, x, y;

void dfs(int V) {
    check[V] = true;
    cout << V << " ";
    for (auto& next : a[V]) {
        if (!check[next]) dfs(next);
    }
}
void bfs(int V) {
    queue<int> q;
    q.push(V);
    check[V] = true;
    while (!q.empty()){
        int cur = q.front(); 
        q.pop();
        cout << cur << " ";
        for (auto& next : a[cur]) {
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

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (auto& list : a) {
        sort(list.begin(), list.end());
    }
    dfs(V);
    cout << "\n";
    memset(check, false, sizeof(check));
    bfs(V);

    return 0;
}
