#include <iostream>
#include <vector>

using namespace std;

vector<int> Parent;

int G, P;
int answer = 0;

void makeSet(int size) {
    Parent.resize(size + 1);

    for (int i = 0; i <= size; i++) {
        Parent[i] = i;
    }
}

int find(int a) {
    if (Parent[a] != a) {
        Parent[a] = find(Parent[a]);  // 경로 압축
    }
    return Parent[a];
}

void merge(int a, int b) {
    if (b <= 0) return;  // 게이트 0 또는 유효하지 않은 게이트와의 병합 방지
    int rootA = find(a);
    int rootB = find(b);

    Parent[rootA] = rootB;  // 단순 합병 (여기서는 문제 요구사항 및 간단함을 위해 순위 병합 사용 안 함)
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> G >> P;

    makeSet(G);

    for (int i = 0; i < P; i++) {
        int gate;
        cin >> gate;

        int availableGate = find(gate);
        if (availableGate == 0) break;

        if (availableGate - 1 >= 1) {
            Parent[availableGate] = find(availableGate - 1);
        }
        else {
            Parent[availableGate] = 0;
        }
        answer++;
    }
    cout << answer << "\n";

    return 0;
}
