#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int inorder[100001];
int postorder[100001];
int idx[100001];

void preorder(int l, int r, int v) {
    if (l > r) return;

    int root = postorder[v];

    cout << root << ' ';

    preorder(l, idx[root] - 1, v - (r - idx[root]) - 1);
    preorder(idx[root] + 1, r, v - 1);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    preorder(0, n - 1, n - 1);

    return 0;
}
