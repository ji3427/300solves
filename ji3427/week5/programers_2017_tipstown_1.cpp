#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<int> st;
    for(int i = 0 ; i < s.length() ; i++){
        if(st.empty()) {
            st.push(s[i]);
            continue;
        }
        if(s[i] == st.top()) st.pop();
        else st.push(s[i]);
    }
    if(st.empty()) return 1;
    return 0;
}