#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(true){
        stack<char> st;
        bool flag = true;

        string input;
        getline(cin, input);

        if(input.length() == 1 && input[0] == '.') break;
        
        for(int i=0;i<input.length();i++){
            if(input[i] == '[' || input[i] == '('){
                st.push(input[i]);
            }

            if(input[i] == ']'){
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }

            if(input[i] == ')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    flag = false;
                    break;
                }
            }

        }

        if(st.empty() && flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }

    return 0;
}