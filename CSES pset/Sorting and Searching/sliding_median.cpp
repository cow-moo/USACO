#include <iostream>
#include <set>
using namespace std;
#define MAXN 200005

int arr[MAXN];
set<pair<int, int>> window;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
        window.insert({arr[i], i});
    }
    auto it = window.begin();
    for (int i = 0; i < (k - 1) / 2; i++)
        it++;
    cout << it->first << " ";
    for (int i = k; i < n; i++)
    {
        cin >> arr[i];
        if (k % 2 == 0)
        {
            window.insert({arr[i], i});
            if (arr[i] >= it->first)
                it++;
        }
        else
        {
            window.insert({arr[i], i});
            if (arr[i] < it->first)
                it--;
        }

        if (k % 2 == 1)
        {
            if (make_pair(arr[i - k], i - k) <= *it)
            {
                it++;
            }
            window.erase({arr[i - k], i - k});
        }
        else
        {
            if (make_pair(arr[i - k], i - k) >= *it)
            {
                it--;
            }
            window.erase({arr[i - k], i - k});
        }

        cout << it->first << " ";
    }
    cout << endl;
}