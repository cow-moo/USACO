#include <iostream>
#include <set>
#include <algorithm>
#include <deque>
using namespace std;
#define MAXN 100005

int adj[MAXN];
deque<int> dq;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 10 << endl;
        return 0;
    }

    int inv = ~(1 << n - 1);

    dq.push_back(0);
    for (int i = 0; i < dq.size(); i++)
    {
        dq.push_front(dq.back());
        dq.pop_back();
        if (adj[dq.front()] != 2)
        {
            int cur = dq.front();
            do
            {
                dq.push_back(cur);
                cur = ((cur << 1) & inv) ^ (adj[cur]++);
            } while (cur != dq.front());
        }
    }

    for (int i = 0; i < n - 2; i++)
        cout << 0;
    while (!dq.empty())
    {
        cout << (dq.front() & 1);
        dq.pop_front();
    }
}