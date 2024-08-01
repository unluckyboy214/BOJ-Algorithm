#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 주어진 부등호 조건을 만족하는지 확인하는 함수
bool isValid(char a, char b, char op) {
    if (op == '<') return a < b;
    if (op == '>') return a > b;
    return false;
}

// 백트래킹을 통해 가능한 모든 숫자 조합을 탐색
void backtrack(int index, string num, vector<bool>& used, const vector<char>& signs, string& max_num, string& min_num) {
    // 주어진 부등호 순서를 만족하는 숫자를 모두 찾음
    if (index == signs.size() + 1) {
        if (min_num.empty() || num < min_num) min_num = num;
        if (max_num.empty() || num > max_num) max_num = num;
        return;
    }

    // 0부터 9까지의 숫자를 시도
    for (int i = 0; i <= 9; ++i) {
        if (!used[i]) {
            if (index == 0 || isValid(num[index - 1], i + '0', signs[index - 1])) {
                used[i] = true;
                backtrack(index + 1, num + to_string(i), used, signs, max_num, min_num);
                used[i] = false;
            }
        }
    }
}

int main() {
    int k;
    cin >> k;

    vector<char> signs(k);
    for (int i = 0; i < k; ++i) {
        cin >> signs[i];
    }

    string max_num = "", min_num = "";
    vector<bool> used(10, false); // 사용한 숫자를 체크하는 배열

    // 백트래킹 시작
    backtrack(0, "", used, signs, max_num, min_num);

    cout << max_num << endl;
    cout << min_num << endl;

    return 0;
}
