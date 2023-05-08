#include <iostream>
#include <set>
using namespace std;
#define MAXN 200005

int code[MAXN], cnt[MAXN];
set<int> leaves;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 2; i++)
    {
        cin >> code[i];
        cnt[code[i]]++;
    }

    for (int i = 1; i < n; i++)
    {
        if (cnt[i] == 0)
        {
            leaves.insert(i);
        }
    }

    for (int i = 0; i < n - 2; i++)
    {
        cout << *leaves.begin() << " " << code[i] << endl;
        leaves.erase(leaves.begin());
        cnt[code[i]]--;
        if (cnt[code[i]] == 0)
            leaves.insert(code[i]);
    }
    
    cout << code[n - 3] << " " << n << endl;
}