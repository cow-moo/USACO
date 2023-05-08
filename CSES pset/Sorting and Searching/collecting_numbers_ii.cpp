#include <iostream>
using namespace std;
#define MAXN 200005

int pos[MAXN], arr[MAXN];

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
    //cout << ans << endl;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        swap(arr[a], arr[b]);
        a = arr[a];
        b = arr[b];
        if (a > b)
            swap(a, b);
        //cout << "a" << a << " " << b << endl;

        if (a != n && pos[a + 1] < pos[a])
        {
            ans--;
        }
        if (a != 1 && pos[a - 1] > pos[a])
        {
            ans--;
        }
        if (b != n && pos[b + 1] < pos[b])
        {
            ans--;
        }
        if (b != 1 && pos[b - 1] > pos[b] && b - a > 1)
        {
            ans--;
        }

        swap(pos[a], pos[b]);

        if (a != n && pos[a + 1] < pos[a])
        {
            ans++;
        }
        if (a != 1 && pos[a - 1] > pos[a])
        {
            ans++;
        }
        if (b != n && pos[b + 1] < pos[b])
        {
            ans++;
        }
        if (b != 1 && pos[b - 1] > pos[b] && b - a > 1)
        {
            ans++;
        }

        cout << ans << endl;
    }
}

/*
5 0
4 2 1 5 3
*/

/*
5 3
4 2 1 5 3
2 3
1 5
2 3
*/