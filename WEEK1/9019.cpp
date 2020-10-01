#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int funcD(int n) {
    return n * 2 % 10000;
}

int funcS(int n) {
    if (n == 0) return 9999;
    else return n - 1;
}

int funcL(int n) {
    return n % 1000 * 10 + n / 1000;
}

int funcR(int n) {
    return n % 10 * 1000 + n / 10;
}

string bfs(int a, int b) {
    queue<pair<int, string>> q;
    bool check[10000];

    memset(check, 0, sizeof(check));
    q.push({a, ""});
    check[a] = true;

    while (!q.empty()) {
        int n = q.front().first;
        string s = q.front().second;

        q.pop();

        int next;

        next = funcD(n);
        if (next == b) return s + 'D';

        if (!check[next]) {
            q.push({next, s + 'D'});
            check[next] = true;
        }

        next = funcS(n);
        if (next == b) return s + 'S';

        if (!check[next]) {
            q.push({next, s + 'S'});
            check[next] = true;
        }

        next = funcL(n);
        if (next == b) return s + 'L';

        if (!check[next]) {
            q.push({next, s + 'L'});
            check[next] = true;
        }

        next = funcR(n);
        if (next == b) return s + 'R';

        if (!check[next]) {
            q.push({next, s + 'R'});
            check[next] = true;
        }
    }
}

int main()
{
    int t;

    cin >> t;

    while (t--) {
        int a, b;

        cin >> a >> b;

        cout << bfs(a, b) << '\n';
    }

    return 0;
}
