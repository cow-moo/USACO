#include <iostream>
using namespace std;
#define MAXN 200005

int nxt[MAXN][30];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> nxt[i][0];
        nxt[i][0]--;
    }

    for (int j = 1; j < 30; j++)
    {
        for (int i = 0; i < n; i++)
        {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, k;
        cin >> x >> k;
        x--;
        for (int j = 0; j < 30; j++)
        {
            if (k & 1)
                x = nxt[x][j];
            k >>= 1;
            if (k == 0)
                break;
        }
        cout << x + 1 << endl;
    }
}