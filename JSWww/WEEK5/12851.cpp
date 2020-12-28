#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, k, time, cnt;
int check[100001];

void bfs() {
    queue<int> q;

    q.push(n);

    while (!cnt) {
        int len = q.size();

        for (int i = 0; i < len; i++) {
            int x = q.front();

            q.pop();

            if (x == k) cnt++;

            for (auto nx : {x-1, x+1, x*2}) {
                if (nx < 0 || nx > 100000) continue;
                if (check[nx] && check[nx] != check[x] + 1) continue;

                check[nx] = check[x] + 1;
                q.push(nx);
            }
        }

        time++;
    }
}

int main()
{
    cin >> n >> k;

    bfs();

    cout << time - 1 << '\n';
    cout << cnt << '\n';

    return 0;
}