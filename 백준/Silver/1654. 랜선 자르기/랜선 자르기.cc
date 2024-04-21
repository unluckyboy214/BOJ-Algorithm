#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll arr[10002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	ll N, K;
	ll start=1;
	cin >> K >> N;
	for (ll i = 0; i < K; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + K);

	ll end = arr[K - 1];
	ll result;

	while (start<=end) {
		ll mid = (start + end) / 2;
		ll cnt = 0;
		for (ll i = 0; i < K; i++) {
			cnt += arr[i] / mid;
		}

		if (cnt < N) end = mid -1;
		else {
			start = mid + 1;
			result = mid;
		}

	}

	cout << result;
	return 0;
}