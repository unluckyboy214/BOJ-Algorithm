#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    
    // DP 테이블 초기화
    vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
    int maxLength = 0; // 가장 긴 공통 부분 문자열의 길이 저장

    // DP 테이블 채우기
    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= B.size(); j++) {
            if (A[i - 1] == B[j - 1]) { // 연속된 공통 문자일 경우
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
            // else 블록은 필요 없음. 기본적으로 0으로 초기화됨
        }
    }

    cout << maxLength;

    return 0;
}
