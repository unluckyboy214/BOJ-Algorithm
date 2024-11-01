#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;

    char target = '0' + k;

    for (int num = i; num <= j; num++) {
        string numStr = to_string(num);
        for (auto& x : numStr) {
            if (x == target) answer++;
        }
    }

    return answer;
}