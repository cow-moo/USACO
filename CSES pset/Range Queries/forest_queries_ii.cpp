#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1005

struct FenwickTree2D {
    vector<vector<int>> bit;
    int n, m;

    // init(...) { ... }
    FenwickTree2D(int n, int m) : n(n), m(m), bit(n, vector<int>(m, 0))
    {}

    int sum(int x, int y) {
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ret += bit[i][j];
        return ret;
    }

    void add(int x, int y, int delta) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] += delta;
    }
};

string forest[MAXN];

int main()
{
    int n, q;
    cin >> n >> q;

    FenwickTree2D tree(n, n);

    for (int i = 0; i < n; i++)
    {
        cin >> forest[i];
        for (int j = 0; j < n; j++)
        {
            if (forest[i][j] == '*')
                tree.add(i, j, 1);
        }
    }

    for (int i = 0; i < q; i++)
    {
        int inp;
        cin >> inp;

        if (inp == 1)
        {
            int y, x;
            cin >> y >> x;
            y--; x--;

            if (forest[y][x] == '*')
            {
                forest[y][x] = '.';
                tree.add(y, x, -1);
            }
            else
            {
                forest[y][x] = '*';
                tree.add(y, x, 1);
            }
        }
        else
        {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            y1--; x1--; y2--; x2--;
            if (y1 > y2)
                swap(y1, y2);
            if (x1 > x2)
                swap(x1, x2);
            cout << tree.sum(y2, x2) - tree.sum(y2, x1 - 1) - tree.sum(y1 - 1, x2) + tree.sum(y1 - 1, x1 - 1) << endl;
        }
    }
}