#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int binary_search(vector<int>& v, int value, int start, int end) {
	if (start > end) return 0;
	
	int mid = (start + end) / 2;

	if (v[mid] == value) return 1;
	
	if (v[mid] > value) return binary_search(v, value, start, mid - 1);
	else return binary_search(v, value, mid + 1, end);

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, value;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> value;
		cout << binary_search(v,value,0,N-1) << "\n";
	}

	return 0;
}