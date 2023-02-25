#include <iostream>
#include <queue>
using namespace std;

struct Trampoline
{
    long long x, y, p;
} trampolines[205];

bool visited[205];
int n;

long long test(int start)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    priority_queue<pair<long long, int>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        long long temp = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur])
            continue;
        visited[cur] = true;
        res = min(res, temp);
        //cout << "a" << temp << endl;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            
            long long dist = abs(trampolines[i].x - trampolines[cur].x) + abs(trampolines[i].y - trampolines[cur].y);
            long long s = dist / trampolines[cur].p + (dist % trampolines[cur].p != 0);
            //cout << cur << ", " << i << ": " << dist << " " << s << endl;
            pq.push({-s, i});
        }
    }
    //cout << start << " " << res << endl;
    return -res;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> trampolines[i].x >> trampolines[i].y >> trampolines[i].p;
    }

    long long ans = -1;
    for (int i = 0; i < n; i++)
    {
        long long res = test(i);        
        if (ans == -1 || res < ans)
            ans = res;
    }

    cout << ans << endl;
}