#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int T = 10;
    for (int test_case = 1; test_case <= T; test_case++) {
        int V, E;
        cin >> V >> E;

        vector<int> inDegree(V + 1, 0);
        vector<vector<int>> graph(V + 1);
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < E; i++) {
            int start, end;
            cin >> start >> end;
            graph[start].push_back(end);
            inDegree[end]++;
        }

        for (int i = 1; i <= V; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);

            for (int next : graph[current]) {
                if (--inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << "#" << test_case << " ";
        for (int node : result) {
            cout << node << " ";
        }
        cout << "\n";
    }
    return 0;
}
