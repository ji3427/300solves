#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> g;
int dist[501];

int main()
{
    int tc;

    cin >> tc;

    while (tc--) {
        int n, m, w;

        cin >> n >> m >> w;

        g.clear();
        g.resize(n + 1);

        dist[1] = 0;

        for (int i = 2; i <= n; i++) {
            dist[i] = 1e9;
        }

        int s, e, t;

        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;

            g[s].push_back({e, t});
            g[e].push_back({s, t});
        }

        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;

            g[s].push_back({e, -t});
        }

        bool ans = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (auto e : g[j]) {
                    int there = e.first;
                    int d = e.second;

                    if (dist[there] > dist[j] + d) {
                        dist[there] = dist[j] + d;
                        if (i == n) ans = true;
                    }
                }
            }
        }

        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
