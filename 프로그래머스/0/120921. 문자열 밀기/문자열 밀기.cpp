#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int n = A.size();
    string extendedA = A + A;

    for (int i = n; i >0; i--) {
        if (!extendedA.compare(i, n, B)) {
            return answer;
            break;
        }
        answer++;
        
    }
    return -1;
}