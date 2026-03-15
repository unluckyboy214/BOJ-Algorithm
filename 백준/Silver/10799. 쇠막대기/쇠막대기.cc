#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string input;
    cin >> input;

    stack<char> st;
    int result = 0;
    for(int i=0;i<input.length();i++){
        if(input[i] == '('){
            st.push(input[i]);
        }
        else{
            st.pop();
            if(input[i-1] == '('){
                result += st.size();
            }
            else{
                result +=1;
            }
        }
    }
    cout << result;
    return 0;
}