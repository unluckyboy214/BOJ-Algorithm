#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // reverse 함수가 정의된 헤더

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;

    stack<char> st;
    size_t bomb_len = bomb.length(); // bomb_len을 부호 없는 정수형으로 선언

    for (char x : str) {
        st.push(x);

        // 스택에 폭발 문자열을 담을 만큼 쌓인 경우
        if (st.size() >= bomb_len) {
            // 스택에서 폭발 문자열의 마지막 부분부터 체크
            string temp;
            for (size_t i = 0; i < bomb_len; i++) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());

            if (temp == bomb) {
                continue; // 폭발 문자열을 제거했으므로 넘어감
            }
            else {
                // 다시 스택에 넣음
                for (char c : temp) {
                    st.push(c);
                }
            }
        }
    }

    // 결과 생성
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    if (result.empty()) {
        cout << "FRULA" << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
