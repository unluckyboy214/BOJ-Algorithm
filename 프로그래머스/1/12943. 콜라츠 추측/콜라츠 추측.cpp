#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0; //반복 작업 회수
    long long number = num;
    if (num == 1) return 0;

    while (true) {

        if (number == 1)
            break;

        number % 2 == 0 ? number /= 2 : number = 3 * number + 1;
        answer++;

        if (answer == 500) {
            answer = -1;
            break;
        }

    }


    return answer;
}