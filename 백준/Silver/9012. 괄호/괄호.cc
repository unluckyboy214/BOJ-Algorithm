#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		bool isValid = true;


		stack<char> st;

		for (auto& x : s) {
			if (x == '(') {
				st.push(x);
			}
			else {
				if (!st.empty() && st.top() == '(' ) st.pop();
				else {
					isValid = false;
					break;
				}
			}
		}

		if (!st.empty()) {
			isValid = false;
		}
		
		if (isValid) cout << "YES" << "\n";
		else cout << "NO" << "\n";

	}

	return 0;
}