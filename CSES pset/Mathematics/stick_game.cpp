#include <iostream>
using namespace std;
#define MAXN 1000005

bool ans[MAXN];
int sticks[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> sticks[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i - sticks[j] >= 0)
            {
                if (!ans[i - sticks[j]])
                {
                    ans[i] = true;
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << (ans[i] ? 'W' : 'L');
    }
    cout << endl;
}