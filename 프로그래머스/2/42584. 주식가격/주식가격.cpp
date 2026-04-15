#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    stack<int> st; // 인덱스 저장

    for (int i = 0; i < n; i++) {
        // 현재 가격이 스택 top의 가격보다 낮으면 → 가격 하락
        while (!st.empty() && prices[st.top()] > prices[i]) {
            int idx = st.top(); st.pop();
            answer[idx] = i - idx; // 떨어진 시점 - 시작 시점
        }
        st.push(i);
    }

    // 스택에 남은 것들 = 끝까지 가격이 안 떨어진 경우
    while (!st.empty()) {
        int idx = st.top(); st.pop();
        answer[idx] = n - 1 - idx;
    }

    return answer;
}