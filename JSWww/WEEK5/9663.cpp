#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, answer = 0;
int col[15];

bool possible(int k) {
    for (int i = 0; i < k; i++) {
        if (col[i] == col[k]) return false;
        if (abs(i - k) == abs(col[i] - col[k])) return false;
    }

    return true;
}

void dfs(int cnt) {
    if (cnt == n) {
        answer++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        col[cnt] = i;
        if (possible(cnt)) dfs(cnt + 1);
    }
}

int main()
{
    cin >> n;

    dfs(0);

    cout << answer << '\n';

    return 0;
}