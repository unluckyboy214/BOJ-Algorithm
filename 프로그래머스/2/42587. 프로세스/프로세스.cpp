#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    // (우선순위, 원래 인덱스)를 저장하는 큐
    queue<pair<int, int>> q;
    // 현재 남은 프로세스 중 최대 우선순위를 빠르게 확인하기 위한 최대 힙
    priority_queue<int> maxHeap;

    for (int i = 0; i < (int)priorities.size(); i++) {
        q.push({priorities[i], i});
        maxHeap.push(priorities[i]);
    }

    int order = 0;

    while (!q.empty()) {
        auto [pri, idx] = q.front();
        q.pop();

        if (pri < maxHeap.top()) {
            // 큐에 더 높은 우선순위가 존재 → 다시 뒤로
            q.push({pri, idx});
        } else {
            // 현재 프로세스가 가장 높은 우선순위 → 실행
            maxHeap.pop();
            order++;
            if (idx == location) {
                return order;
            }
        }
    }

    return order;
}
