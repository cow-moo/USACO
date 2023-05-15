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
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < other.n; j++)
                {
                    res[i][j] += vals[i][k] * other[k][j];
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }

    static Matrix exp(Matrix base, long long exp)
    {
        Matrix res(base.n, base.n);
        for (int i = 0; i < res.n; i++)
        {
            res[i][i] = 1;
        }
        while (exp > 0)
        {
            if (exp & 1)
                res = res * base;
            base = base * base;
            exp >>= 1;
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