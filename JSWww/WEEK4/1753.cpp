#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> dist;

int main()
{
    int v, e, k;

    cin >> v >> e;
    cin >> k;

    g.resize(v);

    int a, b, w;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        g[a-1].push_back({b - 1, w});
    }

    dist.resize(v, 1e9);
    dist[k-1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, k - 1});

    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        if (dist[here] < cost) continue;

        for (auto e : g[here]) {
            int next = e.first;
            int n_cost = e.second;

            if (cost + n_cost < dist[next]) {
                dist[next] = cost + n_cost;
                pq.push({-dist[next], next});
            }
        }
    }

    for (int i = 0; i < v; i++) {
        if (dist[i] == 1e9) cout << "INF\n";
        else cout << dist[i] << '\n';
    }

    return 0;
}
