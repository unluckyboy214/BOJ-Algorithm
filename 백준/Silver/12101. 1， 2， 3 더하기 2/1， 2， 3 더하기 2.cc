#include <iostream>
#include <vector>

using namespace std;

int n, k;
int cnt = 0;
bool found = false;

void DFS(vector<int>& arr, int sum) {
	if (sum > n || found) return;

	if (sum == n) {
		cnt++;
		if (cnt == k) {
			for (int i = 0; i < arr.size(); i++) {
				if (i == arr.size() - 1) cout << arr[i];
				else cout << arr[i] << "+";
			}
			found = true;
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		arr.push_back(i);
		DFS(arr, sum + i);
		arr.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	vector<int> arr;
	DFS(arr, 0);
	if (!found) cout << "-1";

	return 0;
}
