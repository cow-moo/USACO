#include <iostream>
#include <stack>
using namespace std;
#define MAXN 2505
#define MAXM 5005

long long d[MAXN];
int parent[MAXN];
bool cycle[MAXN];
bool visited[MAXN];

struct Edge
{
    int a, b;
    long long x;
} edges[MAXM];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].a >> edges[i].b >> edges[i].x;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (d[edges[j].b] > d[edges[j].a] + edges[j].x)
            {
                d[edges[j].b] = d[edges[j].a] + edges[j].x;
                parent[edges[j].b] = edges[j].a;
                if (i == n - 1)
                    cycle[edges[j].a] = cycle[edges[j].b] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (cycle[i])
        {
            cout << "YES" << endl;
            stack<int> st;
            int cur = i;
            do
            {
                visited[cur] = true;
                st.push(cur);
                cur = parent[cur];
            } while (!visited[cur]);
            
            cout << cur << " ";
            while (!st.empty() && st.top() != cur)
            {
                cout << st.top() << " ";
                st.pop();
            }
            cout << cur << endl;
            
            return 0;
        }
    }

    cout << "NO" << endl;
}