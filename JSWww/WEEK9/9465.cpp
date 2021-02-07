#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dp[2][100001];

int main()
{
    int t, n;

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < 2; i++) {
            int num;

            for (int j = 0; j < n; j++) {
                cin >> num;
                dp[i][j] = num;
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];

        for (int i = 2; i < n; i++) {
            dp[0][i] += max(dp[1][i-2], dp[1][i-1]);
            dp[1][i] += max(dp[0][i-2], dp[0][i-1]);
        }

        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }

    return 0;
}
