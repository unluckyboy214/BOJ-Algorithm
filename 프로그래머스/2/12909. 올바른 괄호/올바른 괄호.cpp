#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> st;

    for (auto& x : s) {
        if (x == '(') {
            st.push(x);
        }
        else {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

