#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minSwapsToGroupA(const string& s) {
    int n = s.size();
    int count_a = count(s.begin(), s.end(), 'a');
    string doubled_s = s + s;  // 원형 문자열을 시뮬레이션하기 위해 두 배로 늘리기

    int min_swaps = n;  // 최대 가능한 값으로 초기화
    int current_b_count = 0;

    // 첫 번째 윈도우
    for (int i = 0; i < count_a; ++i) {
        if (doubled_s[i] == 'b') {
            ++current_b_count;
        }
    }
    min_swaps = current_b_count;

    // 슬라이딩 윈도우로 나머지 확인
    for (int i = count_a; i < 2 * n; ++i) {
        if (doubled_s[i - count_a] == 'b') {
            --current_b_count;
        }
        if (doubled_s[i] == 'b') {
            ++current_b_count;
        }
        min_swaps = min(min_swaps, current_b_count);
    }

    return min_swaps;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    cout << minSwapsToGroupA(s) << endl;
    return 0;
}
