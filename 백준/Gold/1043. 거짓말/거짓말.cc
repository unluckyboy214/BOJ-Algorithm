#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> Parent;
vector<int> Rank;
vector<bool> knowsTruth;
int N, M;

void makeSet(int size) {
    Parent.resize(size + 1);
    Rank.resize(size + 1, 0);
    knowsTruth.resize(size + 1, false);
    for (int i = 1; i <= size; i++) {
        Parent[i] = i;
    }
}

int find(int a) {
    if (Parent[a] != a) {
        Parent[a] = find(Parent[a]);
    }
    return Parent[a];
}

void merge(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA != rootB) {
        if (Rank[rootA] > Rank[rootB]) {
            Parent[rootB] = rootA;
            knowsTruth[rootA] = knowsTruth[rootA] || knowsTruth[rootB];
        }
        else if (Rank[rootA] < Rank[rootB]) {
            Parent[rootA] = rootB;
            knowsTruth[rootB] = knowsTruth[rootB] || knowsTruth[rootA];
        }
        else {
            Parent[rootB] = rootA;
            Rank[rootA]++;
            knowsTruth[rootA] = knowsTruth[rootA] || knowsTruth[rootB];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    makeSet(N);

    int truth, person;
    cin >> truth;
    for (int i = 0; i < truth; i++) {
        cin >> person;
        knowsTruth[find(person)] = true;
    }

    vector<vector<int>> parties(M);
    for (int i = 0; i < M; i++) {
        int partySize;
        cin >> partySize;
        parties[i].resize(partySize);
        cin >> parties[i][0]; 

        for (int j = 1; j < partySize; j++) {
            cin >> parties[i][j];
            merge(parties[i][0], parties[i][j]);
        }
    }

    int lie = 0;
    for (auto& party : parties) {
        int root = find(party[0]);
        if (!knowsTruth[root]) {
            lie++;
        }
    }

    cout << lie << endl;

    return 0;
}
