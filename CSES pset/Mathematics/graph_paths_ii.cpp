#include <iostream>
#include <vector>
using namespace std;
#define INF 2000000000000000000ll

struct Matrix
{
    int m, n;
    vector<vector<long long>> vals;

    Matrix(int m, int n) : m(m), n(n), vals(m, vector<long long>(n, INF)) {}

    vector<long long>& operator[](int i)
    {
        return vals[i];
    }

    Matrix operator*(Matrix &other)
    {
        Matrix res(m, other.n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < other.n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    res[i][j] = min(res[i][j], vals[i][k] + other[k][j]);
                }
            }
        }
        return res;
    }

    void print()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << vals[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    Matrix edges(n, n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges[a - 1][b - 1] = min(edges[a - 1][b - 1], c);
    }

    Matrix res(1, n);
    res[0][0] = 0;

    while (k > 0)
    {
        if (k & 1)
            res = res * edges;
        edges = edges * edges;
        k >>= 1;
    }

    if (res[0][n - 1] >= INF)
        cout << -1 << endl;
    else
        cout << res[0][n - 1] << endl;
}

