#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n;
char b[101][101];
bool visited[101][101];

void bfs(int i, int j, char color) {

    queue<pair<int, int>> q;
    
    q.push({i, j});
    if (color == 'G') b[i][j] = 'R';

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || b[nx][ny] != color) continue;
            if (color == 'G') b[nx][ny] = 'R';

            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

int solve() {

    int result = 0;
     
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue;
            
            bfs(i, j, b[i][j]);
            visited[i][j] = true;
            result++;
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

    cout << solve() << ' ' << solve() << '\n';

    return 0;
}
