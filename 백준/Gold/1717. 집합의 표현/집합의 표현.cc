#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
int x;
vector<int> Parent;
vector<int> Rank;

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

	cin >> n >> m;

	makeSet(n);

	for (int i = 0; i < m; i++) {
		cin >> x >> a >> b;

		if (!x) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b)) cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}


	return 0;
}