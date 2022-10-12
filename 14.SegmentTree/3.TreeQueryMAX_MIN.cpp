#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
int arr[N], tree[4 * N];

void build(int node, int st, int en)
{
    if (st == en)
    {

        tree[node] = arr[st];
        return;
    }

    int mid = (st + en) / 2;

    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int MaxQuery(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return 0;
    }

    if (l <= st && en <= r)
    {
        return tree[node];
    }

    int mid = (st + en) / 2;

    int q1 = MaxQuery(2 * node, st, mid, l, r);
    int q2 = MaxQuery(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
}

int MINQuery(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
    {
        return 0;
    }

    if (l <= st && en <= r)
    {
        return tree[node];
    }

    int mid = (st + en) / 2;

    int q1 = MINQuery(2 * node, st, mid, l, r);
    int q2 = MINQuery(2 * node + 1, mid + 1, en, l, r);

    return min(q1, q2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    while (1)
    {
        int type;
        cin >> type;
        if (type == -1)
        {

            break;
        }

        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = MaxQuery(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
    }
}