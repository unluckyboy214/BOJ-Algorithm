#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	priority_queue<int> heap;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		heap.push(c);
	}

	bool check = true;

	for (int i = 0; i < M; i++) {
		int w;
		cin >> w;

		if (w > heap.top()) {
			check = false;
			break;
		}
		else {
			heap.push(heap.top() - w);
			heap.pop();
		}
	}
	if (check) cout << "1";
	else cout << "0";

	return 0;
}