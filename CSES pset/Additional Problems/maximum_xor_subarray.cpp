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