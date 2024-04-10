#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    queue<int> q;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < K - 1; j++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front()<< ", ";
        q.pop();
    }
    cout <<q.front()<< ">";

    return 0;
}