#include <iostream>
#include <vector>

using namespace std;

vector<int> Parent;
vector<int> Rank;

int N, M;
int x,before_x;


void makeSet(int size) {
	Parent.resize(size + 1);
	Rank.resize(size + 1, 0);
	for (int i = 0; i <= size; i++) {
		Parent[i] = i;
	}
}

int find(int a) {
	//경로 압축
	if (Parent[a] != a) {
		Parent[a] = find(Parent[a]);
	}
	return Parent[a];
}

void merge(int a, int b) {
	int rootA = find(a);
	int rootB = find(b);

	if (rootA != rootB) {
		if (Rank[rootA] > Rank[rootB]) {
			Parent[rootB] = rootA;
		}
		else if (Rank[rootA] < Rank[rootB]) {
			Parent[rootA] = rootB;
		}
		else {
			Parent[rootB] = rootA;
			Rank[rootA] += 1;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin >> M;

	makeSet(N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> x;
			if (x) merge(i, j);
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x;
		if (!i) before_x = find(x);
		else {
			if (before_x != find(x)) {
				cout << "NO";
				break;
			}
		}
		if (i == M - 1) cout << "YES";
		
	}
	

	return 0;
}