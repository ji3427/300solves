#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, e, v1, v2;
int graph[801][801];

int main()
{
    cin >> n >> e;

    int a, b, c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) graph[i][j] = 0;
            else graph[i][j] = 1e6;
        }
    }

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;

        graph[a][b] = c;
        graph[b][a] = c;
    }

    cin >> v1 >> v2;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int first = graph[1][v1] + graph[v1][v2] + graph[v2][n];
    int second = graph[1][v2] + graph[v2][v1] + graph[v1][n];

    int ans = min(first, second);

    cout << (ans < 1e6 ? ans : -1) << '\n';

    return 0;
}
