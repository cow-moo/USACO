#include <iostream>
using namespace std;
#define MAXN 200005

int pos[MAXN];
int arr[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pos[arr[i]] = i;

        if (pos[arr[i] + 1] != 0)
            ans++;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        swap(arr[a], arr[b]);
        a = arr[a];
        b = arr[b];

        if (a != n)
        {
            if (pos[a + 1] < pos[a])
                ans--;
            if (pos[a + 1] < pos[b])
                ans++;
        }

        if (a != 1)
        {
            if (pos[a] < pos[a - 1])
                ans--;
            if (pos[b] < pos[a - 1])
                ans++;
        }

        if (b != n)
        {
            if (pos[b + 1] < pos[b])
                ans--;
            if (pos[b + 1] < pos[a])
                ans++;
        }

        if (b != 1)
        {
            if (pos[b] < pos[b - 1])
                ans--;
            if (pos[a] < pos[b - 1])
                ans++;
        }
        
        swap(pos[a], pos[b]);

        cout << ans << endl;
    }
}

/*
5 0
4 2 1 5 3
*/