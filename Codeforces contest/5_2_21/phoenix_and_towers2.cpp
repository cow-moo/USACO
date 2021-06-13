#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, m, x;
        cin >> n >> m >> x;

        priority_queue<pair<int, int> > pq;

        for (int i = 1; i <= m; i++)
        {
            pq.push({0, i});
        }

        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            int blockh;
            cin >> blockh;

            pair<int, int> top = pq.top();
            pq.pop();

            cout << top.second << " ";
            pq.push({top.first - blockh, top.second});
        }
        cout << endl;
    }
}
