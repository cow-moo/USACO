#include <iostream>
#include <queue>
using namespace std;

//0 - not visited
//1 - to visit
//2 - visited
int visited[1000050];
int coins[105];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    //visited[0] = 1;
    queue<int> q;
    queue<int> next;
    q.push(0);
    int ans = 0;
    while(true)
    {
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
            {
                if (top + coins[i] <= x && visited[top + coins[i]] == 0)
                {
                    next.push(top + coins[i]);
                    visited[top + coins[i]] = 1;
                }
            }
        }
        ans++;
        swap(q, next);
        if (q.empty())
        {
            cout << -1 << endl;
            return 0;
        }
        if (visited[x] == 1)
            break;
    }
    cout << ans << endl;
}
