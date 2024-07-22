#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool canTransform(string s, string t) {
    while (t.size() > s.size()) {
        if (t.back() == 'A') {
            t.pop_back(); // 끝에 'A'가 있으면 제거
        }
        else if (t.back() == 'B') {
            t.pop_back(); // 끝에 'B'가 있으면 제거
            reverse(t.begin(), t.end()); // 문자열을 뒤집기
        }
        else {
            break; // 변환이 불가능한 경우
        }
    }
    return s == t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string S, T;
    cin >> S >> T;

    if (canTransform(S, T)) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
