#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, k, ans;
int check[100001];

int bfs() {
    priority_queue<pair<int, int>> pq;

    pq.push({0, n});

    for (int i = 0; i < 100001; i++) {
        check[i] = 1e9;
    }

    while (!pq.empty()) {
        int dist = -pq.top().first;
        int x = pq.top().second;

        pq.pop();

        if (x == k) {
            return dist;
        }

        for (auto nx : {x+1, x-1, x*2}) {
            if (nx < 0 || nx > 100000) continue;
            int ndist = (nx == x*2) ? dist : dist + 1;
            if (check[nx] <= ndist) continue;
            check[nx] = ndist;
            pq.push({-ndist, nx});
        }
    }
}

int main()
{
    cin >> n >> k;

    cout << bfs() << '\n';

    return 0;
}