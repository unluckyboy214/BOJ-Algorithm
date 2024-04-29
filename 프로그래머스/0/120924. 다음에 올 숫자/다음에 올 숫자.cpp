
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    bool flag1 = false;
    bool flag2 = false;

    for (int i = 2; i < common.size(); i++) {
        //등차수열
        if (common[i] - common[i - 1] == common[i - 1] - common[i - 2]) {
            flag1 = true;
            break;
        }
        else {
            flag2 = true;
            break;
        }

    }
    if (flag1) {
        int d = common[1] - common[0];
        answer = common[common.size() - 1] + d;
    }
    if (flag2) {
        int d = common[1] / common[0];
        answer = common[common.size() - 1] * d;
    }


    return answer;
}