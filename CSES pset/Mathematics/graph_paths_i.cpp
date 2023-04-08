#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000000007ll

struct Matrix
{
    int m, n;
    vector<vector<long long>> vals;

    Matrix(int m, int n) : m(m), n(n), vals(m, vector<long long>(n)) {}

    vector<long long>& operator[](int i)
    {
        return vals[i];
    }

    Matrix operator+(Matrix &other)
    {
        Matrix res(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = vals[i][j] + other[i][j];
            }
        }
        return res;
    }

    Matrix operator-(Matrix &other)
    {
        Matrix res(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = vals[i][j] - other[i][j];
            }
        }
        return res;
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
                    res[i][j] += vals[i][k] * other[k][j];
                    res[i][j] %= MOD;
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
        cin >> a >> b;
        edges[a - 1][b - 1]++;
    }

    Matrix res(1, n);
    res[0][0] = 1;

    while (k > 0)
    {
        if (k & 1)
            res = res * edges;
        edges = edges * edges;
        k >>= 1;
    }

    cout << res[0][n - 1] << endl;
}
