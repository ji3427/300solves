#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct point {
    int x, y, d;
};

// 가로, 대각선, 세로
int dx[] = {0, 1, 1}; 
int dy[] = {1, 1, 0};

int n;
int b[17][17];

bool is_wall(int x, int y) {
    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (b[nx][ny]) return true;
    }

    return false;
}

int bfs() {
    int result = 0;
    queue<point> q;

    q.push({0, 1, 0});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;

        q.pop();

        if (x == n - 1 && y == n - 1)  {
            result++;
            continue;
        }

        for (int i = 0; i < 3; i++) {
            if (abs(d - i) == 2) continue;
            if (i == 1 && is_wall(x, y)) continue;

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (b[nx][ny]) continue;

            q.push({nx, ny, i});
        }
    }

    return result;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        b[n][i] = 1;
        b[i][n] = 1;
    }

    cout << bfs() << '\n';

    return 0;
}
