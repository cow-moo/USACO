#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 200005

struct Node
{
    Node *zero, *one;
    Node() : zero(nullptr), one(nullptr) {}
};

int main()
{
    int n;
    cin >> n;

    Node *root = new Node();

    Node *cur = root;
    for (int i = 29; i >= 0; i--)
    {
        cur->zero = new Node();
        cur = cur->zero;
    }


    int prefix = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prefix ^= x;

        int best = prefix;
        cur = root;
        for (int j = 29; j >= 0; j--)
        {
            if (cur->zero != nullptr && ((prefix & (1 << j)) || cur->one == nullptr))
            {
                cur = cur->zero;
            }
            else
            {
                cur = cur->one;
                best ^= 1 << j;
            }
        }
        ans = max(ans, best);

        cur = root;
        for (int j = 29; j >= 0; j--)
        {
            if (prefix & (1 << j))
            {
                if (cur->one == nullptr)
                    cur->one = new Node();
                cur = cur->one;
            }
            else
            {
                if (cur->zero == nullptr)
                    cur->zero = new Node();
                cur = cur->zero;
            }
        }
    }
    cout << ans << endl;
}

/*
100
52 36 58 16 18 38 14 28 30 36 20 2 28 10 18 40 6 6 34 40 16 16 2 20 60 46 32 16 30 4 28 46 26 20 6 52 62 58 4 40 0 62 4 0 18 28 44 28 16 30 16 60 42 14 54 14 56 0 20 20 34 52 52 14 4 48 10 44 26 16 48 10 8 34 56 56 24 6 12 4 16 18 18 32 20 24 56 42 60 24 30 42 10 14 0 34 6 34 4 60
*/