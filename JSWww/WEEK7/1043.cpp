#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, cnt, p;
int truth[51];
vector<int> party[51];

int main()
{
    cin >> n >> m;
    cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        cin >> p;
        truth[p] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> p;
            party[i].push_back(p);
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        bool is_truth = false;
        bool is_false = false;

        for (auto e : party[i]) {
            if (truth[e]) is_truth = true;
            else is_false = true;

            if (is_truth && is_false) {
                for (auto e : party[i]) truth[e] = 1;
                ans = 0;
                i = -1;
                break;
            }
        }

        if (!is_truth && is_false) ans++;
    }

    cout << ans << '\n';

    return 0;
}