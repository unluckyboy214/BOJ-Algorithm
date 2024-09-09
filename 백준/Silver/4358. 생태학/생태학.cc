#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string x;

	map<string, double> trees;

	int Tree_cnt = 0;

	while (!(getline(cin, x)).eof()) {
		Tree_cnt++;

		//나무가 있음
		if (trees.find(x) != trees.end()) {
			trees[x]++;
		}

		//나무가 없음
		else {
			trees[x] = 1;
		}

	}

	for (auto& x : trees) {
		cout << fixed;
		cout.precision(4);
		cout << x.first << " " << (x.second / Tree_cnt)*100 << "\n";
	}


	return 0;
}