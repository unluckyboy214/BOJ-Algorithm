#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, a ,b;
	cin >> N;
	
	cout << "? 1" << endl;
	cin >> a;
	cout << "? " << N << endl;
	cin >> b;

	if (a == 1 && b == 0)
		cout << "! -1" << endl;
	else if (a == 0 && b == 1)
		cout << "! 1" << endl;
	else
		cout << "! 0" << endl;

	return 0;
}