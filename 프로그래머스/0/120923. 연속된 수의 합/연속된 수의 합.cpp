
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    int first;

    first = (((2 * total) / num) + 1 - num) / 2;
    
    for (int i = first; i <= first+num-1; i++) {
        answer.push_back(i);
    }

    return answer;
}