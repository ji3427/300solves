#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;

    cin >> t;

    while (t--) {
        int k, n;
        char c;
        multiset<int> s;

        cin >> k;

        for (int i = 0; i < k; i++) {
            cin >> c >> n;

            if (c == 'I') {
                s.insert(n);
            } else {
                if (s.size() == 0) continue;

                if (n == 1) s.erase(--s.end());
                else s.erase(s.begin());
            }
        }

        if (s.size() == 0) cout << "EMPTY\n";
        else cout << *(--s.end()) << ' ' << *(s.begin()) << '\n';
    }

    return 0;
}
