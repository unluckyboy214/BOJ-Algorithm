#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie();

	int N;
	cin >> N;

	vector<double> scores(N);
	double Max_score = 0.0;
	double Sum = 0.0;

	for (int i = 0; i < N; i++) {
		cin >> scores[i];
		if (scores[i] > Max_score) Max_score = scores[i];
	}

	for (int i = 0; i < N; i++) {
		scores[i] = (scores[i] / Max_score) * 100;
		Sum += scores[i];
	}

	cout << Sum / N;

	return 0;
}