#include <iostream>
#include <queue>
using namespace std;
#define MAXN 200005

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int x, n;
    cin >> x >> n;

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        pq.push(d);
    }

    long long ans = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout << ans << endl;
}