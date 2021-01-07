#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};

int r, c, t;
int b[51][51];

vector<int> ro;
int arr[51][51];

void spread() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) {
                    continue;
                }

                if (b[nx][ny] == -1) {
                    continue;
                }

                arr[nx][ny] += b[i][j] / 5;
                cnt++;
            }

            b[i][j] -= (b[i][j] / 5) * cnt;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            b[i][j] += arr[i][j];
            arr[i][j] = 0;
        }
    }
}

void air_cleaner() {
    queue<int> q;

    // 위쪽 회전

    for (int i = 1; i < c; i++) {
        q.push(b[ro[0]][i]);
    }
    for (int i = ro[0] - 1; i > 0; i--) {
        q.push(b[i][c-1]);
    }
    for (int i = c - 1; i > 0; i--) {
        q.push(b[0][i]);
    }
    for (int i = 0; i < ro[0] - 1; i++) {
        q.push(b[i][0]);
    }

    b[ro[0]][1] = 0;

    for (int i = 2; i < c; i++) {
        b[ro[0]][i] = q.front();
        q.pop();
    }
    for (int i = ro[0] - 1; i > 0; i--) {
        b[i][c-1] = q.front();
        q.pop();
    }
    for (int i = c - 1; i > 0; i--) {
        b[0][i] = q.front();
        q.pop();
    }
    for (int i = 0; i < ro[0]; i++) {
        b[i][0] = q.front();
        q.pop();
    }

    // 아래쪽 회전

    for (int i = 1; i < c; i++) {
        q.push(b[ro[1]][i]);
    }
    for (int i = ro[1] + 1; i < r; i++) {
        q.push(b[i][c-1]);
    }
    for (int i = c - 2; i > 0; i--) {
        q.push(b[r-1][i]);
    }
    for (int i = r - 1; i > ro[1] + 1; i--) {
        q.push(b[i][0]);
    }

    b[ro[1]][1] = 0;

    for (int i = 2; i < c; i++) {
        b[ro[1]][i] = q.front();
        q.pop();
    }
    for (int i = ro[1] + 1; i < r; i++) {
        b[i][c-1] = q.front();
        q.pop();
    }
    for (int i = c - 2; i > 0; i--) {
        b[r-1][i] = q.front();
        q.pop();
    }
    for (int i = r - 1; i > ro[1]; i--) {
        b[i][0] = q.front();
        q.pop();
    }
}

int solve() {

    for (int time = 0; time < t; time++) {
        spread();
        air_cleaner();
    }

    int result = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] == -1) {
                continue;
            }
            
            result += b[i][j];
        }
    }

    return result;
}

int main()
{
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];

            if (b[i][j] == -1) {
                ro.push_back(i);
            }
        }
    }

    sort(ro.begin(), ro.end());

    cout << solve() << '\n';

    return 0;
}