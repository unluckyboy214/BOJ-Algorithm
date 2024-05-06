#include <iostream>
#include <vector>

using namespace std;

void getSome(int y, int howmany, int& ans, vector<bool>& Visited, vector<bool>& VisitedIncrease, vector<bool>& VisitedDecrease) {
    if (y > howmany) {
        ans++;
        return;
    }
    for (int x = 1; x <= howmany; ++x) {
        if (!Visited[x] && !VisitedIncrease[y + x] && !VisitedDecrease[y - x + howmany]) {
            Visited[x] = VisitedIncrease[y + x] = VisitedDecrease[y - x + howmany] = true;
            getSome(y + 1, howmany, ans, Visited, VisitedIncrease, VisitedDecrease);
            Visited[x] = VisitedIncrease[y + x] = VisitedDecrease[y - x + howmany] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int N;
    cin >> N;
    int ans = 0;

    vector<bool> Visited(N + 1, false);
    vector<bool> VisitedIncrease(2 * N + 1, false);
    vector<bool> VisitedDecrease(2 * N + 1, false);

    getSome(1, N, ans, Visited, VisitedIncrease, VisitedDecrease);

    cout << ans;

    return 0;
}
