#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    vector<bool> wall(n + 1, true);

    for (int index : section) {
        wall[index] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!wall[i]) {
            answer++;
            int maxPaint = min(n, i + m - 1);
            for (int j = i; j <= maxPaint; j++) {
                wall[j] = true;
            }
        }
    }

    return answer;
}
