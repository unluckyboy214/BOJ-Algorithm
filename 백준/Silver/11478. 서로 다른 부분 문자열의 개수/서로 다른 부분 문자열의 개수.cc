#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string S;
    cin >> S;

    set<string> subs;

    for (int i = 0; i < S.length(); ++i) {
        for (int j = 1; i + j <= S.length(); ++j) {
            subs.insert(S.substr(i, j));
        }
    }

    cout << subs.size();

    return 0;
}
