#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>  // scanf, printf 사용

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> sequence(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }
    
    stack<int> st;
    vector<char> operations;
    int current = 1;
    
    for (int i = 0; i < n; i++) {
        int value = sequence[i];
        
        while (current <= value) {
            st.push(current);
            operations.push_back('+');
            current++;
        }
        
        if (st.top() == value) {
            st.pop();
            operations.push_back('-');
        } else {
            printf("NO\n");
            return 0;
        }
    }
    
    for (char op : operations) {
        printf("%c\n", op);
    }
    
    return 0;
}
