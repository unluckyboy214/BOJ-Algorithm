#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;
    int result = 0;
    while(N--){
        stack<char> st;
        string word;
        cin >> word;

        for(int i=0;i<word.length();i++){
            if(word[i] == 'A'){
                if(!st.empty() && st.top() == 'A'){
                    st.pop();
                }
                else st.push(word[i]);
            }
            else{
                if(!st.empty() && st.top() == 'B'){
                    st.pop();
                }
                else st.push(word[i]);
            }
        }
        
        if(st.empty()) result++;
        else continue; 

    }
    cout << result;
    return 0;
}