#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    // 모든 번호를 set에 저장
    unordered_set<string> s(phone_book.begin(), phone_book.end());

    for (const string& number : phone_book) {
        // 각 번호의 접두어를 하나씩 잘라서 set에 있는지 확인
        for (int len = 1; len < number.size(); len++) {
            string prefix = number.substr(0, len);
            if (s.count(prefix)) {
                return false; // 접두어가 존재함
            }
        }
    }
    return true;
}
