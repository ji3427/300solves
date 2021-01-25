#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> g[801];
int visited[801];
priority_queue<pair<int, int>> pq;

void solve(int v) {
    for (int i = 1; i <= n; i++) {
        visited[i] = 1e6;
    }

    visited[v] = 0;

    pq.push({0, v});

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int here = pq.top().second;

        pq.pop();

        for (auto e : g[here]) {
            int ndist = e.second + dist;
            int next = e.first;

            if (ndist < visited[next]) {
                visited[next] = ndist;
                pq.push({-ndist, next});
            }
        }
    }
}

int main()
{
    cin >> n >> e;

    int a, b, c;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;

        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    int ans1 = 0, ans2 = 0;

    solve(1);
    ans1 += visited[v1];
    ans2 += visited[v2];
    solve(v1);
    ans1 += visited[v2];
    ans2 += visited[n];
    solve(v2);
    ans1 += visited[n];
    ans2 += visited[v1];

    ans1 = min(ans1, ans2);

    cout << (ans1 < 1e6 ? ans1 : -1) << '\n';

    return 0;
}
