#include <iostream>
#include <set>
#include <map>

using namespace std;

struct Problem {
    int P; // 문제 번호
    int L; // 난이도

    // set에서 자동 정렬을 위해 비교 연산자를 정의합니다.
    bool operator<(const Problem& other) const {
        if (L == other.L) {
            return P < other.P;
        }
        return L < other.L;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    set<Problem> problems;  // 난이도 기준으로 정렬되는 문제 리스트
    map<int, int> problem_map;  // 문제 번호를 키로, 난이도를 값으로 저장

    // 초기 문제 리스트 입력
    for (int i = 0; i < N; ++i) {
        int P, L;
        cin >> P >> L;
        problems.insert({ P, L });
        problem_map[P] = L;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        string command;
        cin >> command;

        if (command == "add") {
            int P, L;
            cin >> P >> L;
            problems.insert({ P, L });
            problem_map[P] = L;
        }
        else if (command == "recommend") {
            int x;
            cin >> x;
            if (x == 1) {
                // 가장 어려운 문제를 출력
                cout << prev(problems.end())->P << '\n';
            }
            else {
                // 가장 쉬운 문제를 출력
                cout << problems.begin()->P << '\n';
            }
        }
        else if (command == "solved") {
            int P;
            cin >> P;
            int L = problem_map[P];  // 문제 번호 P에 대한 난이도를 가져옴
            problems.erase({ P, L });  // set에서 (문제 번호, 난이도) 쌍으로 삭제
            problem_map.erase(P);    // map에서 문제 번호 P 삭제
        }
    }

    return 0;
}
