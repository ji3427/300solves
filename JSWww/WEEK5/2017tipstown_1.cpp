#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool delete_pairs(string& s) {
    stack<char> st;
    
    for (auto e : s) {
        if (st.empty() || st.top() != e) {
            st.push(e);
        } else {
            st.pop();
        }
    }
    
    return st.empty();
}

int solution(string s)
{
    int answer = 0;
    
    answer = delete_pairs(s);

    return answer;
}