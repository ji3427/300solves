#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

int main()
{
    string expr, ans = "";
    stack<char> st;
    map<char, int> m;

    m['('] = 0;
    m['+'] = 1; m['-'] = 1;
    m['*'] = 2; m['/'] = 2;

    cin >> expr;

    for (auto e : expr) {
        if (e >= 'A' && e <= 'Z') {
            ans += e;
        } else if (st.empty() || e == '(') {
            st.push(e);
        } else if (e == ')') {
            while (st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            st.pop();
        } else {
            while (!st.empty()) {
            if (m[e] > m[st.top()]) break;
                ans += st.top();
                st.pop();
            }

            st.push(e);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    cout << ans << '\n';

    return 0;
}
