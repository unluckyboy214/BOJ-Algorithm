#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (true) {
        if (n < a) break;

        int new_coke = (n / a) * b;
        answer += new_coke;
        n = n % a;
        n = n + new_coke;

    }

    return answer;
}