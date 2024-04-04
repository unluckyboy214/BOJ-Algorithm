#include <iostream>
#include <cstring>

using namespace std;
int arr[101][101] = { 0, };
int visited[101] = { 0, };

int DFS(int x) {
	if (x == 99) return 1;
	visited[x] = 1;

	for (int i = 0; i < 100; i++) {
		if (arr[x][i] == 1 && visited[i] == 0) {
			if (DFS(i)) return 1;
		}
		
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tc, edge, start, end;

	while (true) {
		cin >> tc >> edge;

		memset(arr, 0, sizeof(arr));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < edge; i++) {
			cin >> start >> end;
			arr[start][end] = 1;
		}
		
		cout << "#" << tc << " " << DFS(0) << "\n";

		if (tc == 10) break;
	}
	


	return 0;
}