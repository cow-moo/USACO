#include <iostream>
#include <vector>
using namespace std;
#define BIT_SIZE 1000

struct FenwickTree
{
    int bit[BIT_SIZE];

    FenwickTree(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            bit[i] = 0;
        }
    }

    int sum(int i)
    {
        i++;
        int sum = 0;
        while (i > 0)
        {
            sum += bit[i];
            i -= (i) & -(i);
        }
        return sum;
    }

    void add(int i, int delta)
    {
        i++;
        while (i <= BIT_SIZE)
        {
            bit[i] += delta;
            i += (i) & -(i);
        }
    }
};

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

int main()
{
    FenwickTree bit(100);
    bit.add(3, 3);
    cout << bit.sum(4) << endl;
    //add(3, 3);
    //add(5, 34);
    //sum adds everything up to and including i
    //cout << sum(3) - sum(2) << endl;
}

//0 1 2 3 4 5 6 7
//7 3 4 6 2 1 4 8
//- - - - - 1 4 8
//- - - - -1312 8
//13