#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	string s;
	string x = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;

	for (int i = 0; i < x.length(); i++) {
		cout << (int)s.find(x[i]) << " ";
	}

	return 0;
}