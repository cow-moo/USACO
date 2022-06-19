#include <iostream>
#include <queue>
using namespace std;

bool visited[1000050];

int main()
{
    int n;
    cin >> n;

    queue<int> q;
    queue<int> next;
    q.push(n);
    int ans = 0;
    while(true)
    {
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            //find next
            int temp = top;
            while (temp > 0)
            {
                if (!visited[top - temp % 10])
                {
                    visited[top - temp % 10] = true;
                    next.push(top - temp % 10);
                }
                temp /= 10;
            }
        }
        ans++;
        swap(q, next);

        if (visited[0])
            break;
    }
    cout << ans << endl;
}
