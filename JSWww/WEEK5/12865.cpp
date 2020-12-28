#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector<pair<int, int>> arr;
int dp[101][100001];

int main()
{
    cin >> n >> k;

    int w, v;

    arr.push_back({0, 0});

    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        arr.push_back({w, v});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            w = arr[i].first;
            v = arr[i].second;

            if (j < w) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], v + dp[i-1][j-w]);
            }
        }
    }

    cout << dp[n][k] << '\n';

    return 0;
}