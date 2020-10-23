#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> g;

int bfs(int start, int end, int n) {
    queue<int> q;
    vector<int> v(n, 1e9);
    
    q.push(start);
    v[start] = 0;

    while (!q.empty()) {
        int here = q.front();

        q.pop();

        if (here == end) continue;

        for (int i = 0; i < g[here].size(); i++) {
            if (g[here][i] == 1e9) continue;
            if (v[i] < v[here] + g[here][i]) continue;

            q.push(i);
            v[i] = v[here] + g[here][i];
        }
    }

    return v[end];
}

int main()
{
    int n, m;

    cin >> n;
    cin >> m;

    g.resize(n, vector<int>(n, 1e9));

    int a, b, c;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a-1][b-1] = min(g[a-1][b-1], c);
    }

    int start, end;

    cin >> start >> end;

    cout << bfs(start - 1, end - 1, n) << '\n';

    return 0;
}
