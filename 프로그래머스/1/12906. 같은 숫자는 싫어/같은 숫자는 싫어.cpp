#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    queue<int> q;
    for (auto& x : arr) {
        q.push(x);
    }
    
    answer.push_back(q.front());
    q.pop();

    while (!q.empty()) {
        if (q.front() == answer.back()) {
            q.pop();
        }
        else {
            int temp = q.front();
            answer.push_back(temp);
            q.pop();
        }
    }

    return answer;
}