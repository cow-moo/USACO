#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
#define MOD 1000000007ll

struct Matrix
{
    int m, n;
    vector<vector<double>> vals;

    Matrix(int m, int n, bool identity = false) : m(m), n(n), vals(m, vector<double>(n))
    {
        if (identity)
        {
            for (int i = 0; i < m; i++)
                vals[i][i] = 1;
        }
    }
    Matrix(vector<vector<double>> arr) : m(arr.size()), n(arr[0].size()), vals(arr) {}

    vector<double>& operator[](int i)
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
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < other.n; j++)
                {
                    res[i][j] += vals[i][k] * other[k][j];
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

Matrix transition(64, 64);

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int cnt = 4;
            if (i == 0 || i == 7)
                cnt--;
            if (j == 0 || j == 7)
                cnt--;

            pair<int, int> cands[] = {{i + 1, j}, {i - 1, j}, {i, j - 1}, {i, j + 1}};
            for (int k = 0; k < 4 ; k++)
            {
                auto [newi, newj] = cands[k];
                if (newi < 0 || newi >= 8 || newj < 0 || newj >= 8)
                    continue;
                transition[8 * i + j][8 * newi + newj] = 1.0 / cnt;
            }
        }
    }

    int k;
    cin >> k;

    Matrix res(64, 64, true);
    // while (k > 0)
    // {
    //     if (k & 1)
    //         res = res * transition;
    //     transition = transition * transition;
    //     k >>= 1;
    // }
    for (int i = 0; i < k; i++)
    {
        res = res * transition;
    }

    double ans = 0;
    for (int i = 0; i < 64; i++)
    {
        double p = 1;
        for (int j = 0; j < 64; j++)
        {
            p *= 1 - res[j][i];
        }
        ans += p;
    }
    cout << fixed << setprecision(6) << ans << endl;
}