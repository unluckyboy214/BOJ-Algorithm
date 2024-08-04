#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; ++i) {
        int id, start, end;
        cin >> id >> start >> end;
        lectures[i] = { start, end };
    }

    // 시작 시간으로 강의 정렬
    sort(lectures.begin(), lectures.end());

    // 우선순위 큐 사용: 강의실의 종료 시간을 저장
    priority_queue<int, vector<int>, greater<int>> endTimes;

    for (const auto& lecture : lectures) {
        int start = lecture.first;
        int end = lecture.second;

        // 가장 빠른 종료 시간이 현재 강의 시작 시간보다 작거나 같으면 강의실 재사용
        if (!endTimes.empty() && endTimes.top() <= start) {
            endTimes.pop();
        }

        // 현재 강의의 종료 시간을 큐에 추가
        endTimes.push(end);
    }

    // 필요한 최소 강의실 수는 우선순위 큐의 크기
    cout << endTimes.size() << endl;

    return 0;
}
