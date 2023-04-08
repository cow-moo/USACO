#include <iostream>
using namespace std;
#define MAXN 200005

int arr[MAXN];
int ans[MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int cur = i - 1;
        while (cur > 0 && arr[cur] >= arr[i])
        {
            cur = ans[cur];
        }
        ans[i] = cur;
        cout << ans[i] << " ";
    }
    cout << endl;
}
