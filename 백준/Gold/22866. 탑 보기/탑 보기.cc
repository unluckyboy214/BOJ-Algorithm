#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);  // 입출력 속도 향상
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    vector<int> heights(N);  // 건물의 높이 배열
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    vector<int> result(N, 0);           // 각 건물이 볼 수 있는 건물 수
    vector<int> closest_building(N, -1);  // 가장 가까운 건물의 인덱스 저장 (0-based)

    // 왼쪽 방향 탐색
    stack<int> s_left;
    for (int i = 0; i < N; ++i) {
        while (!s_left.empty() && heights[s_left.top()] <= heights[i]) {
            s_left.pop();
        }
        if (!s_left.empty()) {
            result[i] += s_left.size();
            if (closest_building[i] == -1 || abs(i - s_left.top()) < abs(i - closest_building[i])) {
                closest_building[i] = s_left.top();
            }
            else if (abs(i - s_left.top()) == abs(i - closest_building[i]) && s_left.top() < closest_building[i]) {
                closest_building[i] = s_left.top();
            }
        }
        s_left.push(i);
    }

    // 오른쪽 방향 탐색
    stack<int> s_right;
    for (int i = N - 1; i >= 0; --i) {
        while (!s_right.empty() && heights[s_right.top()] <= heights[i]) {
            s_right.pop();
        }
        if (!s_right.empty()) {
            result[i] += s_right.size();
            if (closest_building[i] == -1 || abs(i - s_right.top()) < abs(i - closest_building[i])) {
                closest_building[i] = s_right.top();
            }
            else if (abs(i - s_right.top()) == abs(i - closest_building[i]) && s_right.top() < closest_building[i]) {
                closest_building[i] = s_right.top();
            }
        }
        s_right.push(i);
    }

    // 결과 출력
    for (int i = 0; i < N; ++i) {
        if (result[i] > 0) {
            cout << result[i] << " " << closest_building[i] + 1 << '\n';  // 건물 번호는 1부터 시작하므로 +1
        }
        else {
            cout << "0\n";
        }
    }

    return 0;
}
