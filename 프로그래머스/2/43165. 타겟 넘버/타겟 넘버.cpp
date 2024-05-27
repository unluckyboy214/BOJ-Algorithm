#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 0;

void BFS(vector<int>& numbers, int target) {
    queue<pair<int, int>> q;
    int idx = 0;
    q.push(make_pair(idx, numbers[idx]));
    q.push(make_pair(idx, -numbers[idx]));

    while (!q.empty()) {
        int currentIdx = q.front().first;
        int currentSum = q.front().second;
        q.pop();

        if (currentIdx == numbers.size() - 1) {
            if (currentSum == target) {
                answer++;
            }
            continue;
        }

        int nextIdx = currentIdx + 1;
        if (nextIdx < numbers.size()) {
            q.push(make_pair(nextIdx, currentSum + numbers[nextIdx]));
            q.push(make_pair(nextIdx, currentSum - numbers[nextIdx]));
        }
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    if (!numbers.empty()) {
        BFS(numbers, target);
    }
    return answer;
}
