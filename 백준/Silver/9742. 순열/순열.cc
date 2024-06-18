#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int position;

    while (cin >> s >> position) {
        int count = 1;
        bool found = false;

        cout << s << " " << position << " = ";

        if (position == 1) {
            cout << s << endl;
            continue;
        }

        while (next_permutation(s.begin(), s.end())) {
            count++;
            if (count == position) {
                cout << s << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "No permutation" << endl;
        }
    }

    return 0;
}
