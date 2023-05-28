#include <iostream>
#include <vector>
using namespace std;
#define MAXN 105
#define MOD 1000000007ll
 
//prefix[i] is longest proper prefix = suffix for s[0..i]
int prefix[MAXN];
 
void prefix_function(string s)
{
    for (int i = 1; i < s.length(); i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && s[i] != s[j])
            j = prefix[j - 1];
        j += s[i] == s[j];
        prefix[i] = j;
    }
}
 
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
 
bool visited[30];
 
long long exp(long long base, long long exp)
{
    long long res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}
 
int main()
{
    int n;
    string s;
    cin >> n >> s;
 
    prefix_function(s);
 
    Matrix transition(s.length(), s.length());
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 26; j++)
            visited[j] = false;
        int cnt = 25;
        int cur = i;
        if (cur + 1 != s.length())
            transition[cur + 1][i] = 1;
        visited[s[cur] - 'A'] = true;
        while (cur > 0)
        {
            cur = prefix[cur - 1];
            //cout << cur << endl;
            //cout << s[cur] - 'A' << endl;
            if (!visited[s[cur] - 'A'])
            {
                transition[cur + 1][i] = 1;
                visited[s[cur] - 'A'] = true;
                cnt--;
            }
        }
        transition[0][i] = cnt;
    }
    //transition.print();
    transition = Matrix::exp(transition, n);
    //transition.print();
    long long ans = exp(26, n);
    for (int i = 0; i < s.length(); i++)
    {
        ans = ans - transition[i][0] < 0 ? ans - transition[i][0] + MOD : ans - transition[i][0];
    }
    cout << ans << endl;
}