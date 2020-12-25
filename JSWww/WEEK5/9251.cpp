#include <iostream>
#include <string>
#include <vector>

using namespace std;

int b[1001][1001];

int main()
{
    string s1, s2;
    bool flag = false;

    cin >> s1;
    cin >> s2;

    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[0]) flag = true;
        if (flag) b[i][0] = 1;
    }

    flag = false;

    for (int i = 0; i < s2.size(); i++) {
        if (s1[0] == s2[i]) flag = true;
        if (flag) b[0][i] = 1;
    }

    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                b[i][j] = b[i-1][j-1] + 1;
            }
            b[i][j] = max(b[i-1][j], max(b[i][j-1], b[i][j]));
        }
    }

    cout << b[s1.size() - 1][s2.size() - 1] << '\n';

    return 0;
}