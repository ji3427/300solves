#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;

int main()
{
    int n, m, a, b, c;

    cin >> n;
    cin >> m;

    g.resize(n + 1, vector<int>(n + 1, 1e9));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        if (c < g[a][b]) g[a][b] = c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || g[i][j] == 1e9) cout << 0 << ' ';
            else cout << g[i][j] << ' ';
        }
        
        cout << '\n';
    }

    return 0;
}
