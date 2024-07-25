#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    vector<int> positions(M);

    // 초기 큐 설정
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    // 뽑아내려는 위치 입력
    for (int i = 0; i < M; i++) {
        cin >> positions[i];
    }

    int total_operations = 0;

    for (int i = 0; i < M; i++) {
        int target = positions[i];

        // 현재 위치를 찾음
        int index = find(dq.begin(), dq.end(), target) - dq.begin();

        // 왼쪽으로 이동하는 경우와 오른쪽으로 이동하는 경우를 비교
        int left_operations = index;
        int right_operations = dq.size() - index;

        // 최소 연산 횟수를 더함
        total_operations += min(left_operations, right_operations);

        // 최소 연산 횟수로 목표 원소를 앞으로 이동
        if (left_operations <= right_operations) {
            for (int j = 0; j < left_operations; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for (int j = 0; j < right_operations; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        // 첫 번째 원소 제거
        dq.pop_front();
    }

    cout << total_operations << endl;

    return 0;
}
