#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 앞에 불필요한 0을 제거
string getResultWithoutUnnecessaryZeros(string result) {
    int firstNonZeroIdx = result.size();

    for (int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            firstNonZeroIdx = i;
            break;
        }
    }

    if (firstNonZeroIdx == result.size()) {
        return "0";
    }

    return result.substr(firstNonZeroIdx);
}

// bigInteger 덧셈 함수
string add(string s1, string s2) {
    string result(max(s1.size(), s2.size()), '0');

    bool carry = false;

    for (int i = 0; i < result.size(); i++) {
        int temp = carry;
        carry = false;

        if (i < s1.size()) {
            temp += s1[s1.size() - i - 1] - '0';
        }

        if (i < s2.size()) {
            temp += s2[s2.size() - i - 1] - '0';
        }

        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }

        result[result.size() - i - 1] = temp + '0';
    }

    if (carry) {
        result.insert(result.begin(), '1');
    }

    return getResultWithoutUnnecessaryZeros(result);
}

// s1이 s2보다 큰지 여부를 판별하는 함수
bool isFormerBiggerThanLatter(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return s1.size() > s2.size();
    }

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == s2[i]) {
            continue;
        }
        return s1[i] > s2[i];
    }

    return false;
}

// bigInteger 뺄셈 함수 (부호는 판별 X)
string subtract(string s1, string s2) {
    if (isFormerBiggerThanLatter(s1, s2) == false) {
        swap(s1, s2);
    }

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string result = s1;
    int carry = 0;

    for (int i = 0; i < result.size(); i++) {
        int tempCarry = carry;
        carry = 0;

        int temp = (s1[i] - '0') - tempCarry;

        if (temp < 0) {
            carry = 1;
            temp += 10;
        }

        if (i < s2.size()) {
            temp -= (s2[i] - '0');

            if (temp < 0) {
                carry = 1;
                temp += 10;
            }
        }

        result[i] = temp + '0';
    }

    reverse(result.begin(), result.end());
    return getResultWithoutUnnecessaryZeros(result);
}

// bigInteger 곱셈 구현
string multiply(string s1, string s2) {
    string result = "0";

    for (int i = 0; i < s2.size(); i++) {
        string line(s1);
        int carry = 0;

        for (int j = s1.size() - 1; j >= 0; j--) {
            int temp = carry;
            carry = 0;

            temp += (s1[j] - '0') * (s2[s2.size() - (i + 1)] - '0');

            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }

            line[j] = temp + '0';
        }

        if (carry > 0) {
            line.insert(line.begin(), carry + '0');
        }

        line += string(i, '0');
        result = add(result, line);
    }

    return getResultWithoutUnnecessaryZeros(result);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string A, B;
    cin >> A >> B;

    int APositive = A[0] != '-';
    int BPositive = B[0] != '-';

    if (APositive && BPositive) {
        cout << add(A, B) << "\n";

        if (isFormerBiggerThanLatter(A, B) == false && A != B) {
            cout << "-";
        }
        cout << subtract(A, B) << "\n";

        cout << multiply(A, B) << "\n";
    }
    else if (APositive == false && BPositive == false) {
        cout << "-" << add(A.substr(1), B.substr(1)) << "\n";

        if (isFormerBiggerThanLatter(A.substr(1), B.substr(1))) {
            cout << "-";
        }
        cout << subtract(A.substr(1), B.substr(1)) << "\n";

        cout << multiply(A.substr(1), B.substr(1)) << "\n";
    }
    else if (APositive && BPositive == false) {
        string tempResult = subtract(A, B.substr(1));

        if (isFormerBiggerThanLatter(A, B.substr(1)) || tempResult == "0") {
            cout << tempResult << "\n";
        }
        else {
            cout << "-" << tempResult << "\n";
        }

        cout << add(A, B.substr(1)) << "\n";
        cout << "-" << multiply(A, B.substr(1)) << "\n";
    }
    else if (APositive == false && BPositive) {
        string tempResult = subtract(A.substr(1), B);

        if (isFormerBiggerThanLatter(A.substr(1), B) && tempResult != "0") {
            cout << "-" << tempResult << "\n";
        }
        else {
            cout << tempResult << "\n";
        }

        cout << "-" << add(A.substr(1), B) << "\n";
        cout << "-" << multiply(A.substr(1), B) << "\n";
    }

    return 0;
}
