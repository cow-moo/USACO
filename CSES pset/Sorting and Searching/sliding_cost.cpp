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
    long long cost = 0;
    auto it = window.begin();
    for (int i = 0; i < (k - 1) / 2; i++)
    {
        cost -= it->first;
        it++;
    }
    auto temp = it;
    temp++;
    for (int i = (k - 1) / 2 + 1; i < k; i++)
    {
        cost += temp->first;
        temp++;
    }
    cout << cost - (k % 2 == 0 ? it->first : 0) << " ";
    for (int i = k; i < n; i++)
    {
        cin >> arr[i];
        if (k % 2 == 0)
        {
            window.insert({arr[i], i});
            if (arr[i] >= it->first)
            {
                cost += arr[i];

                cost -= it->first;
                it++;
                cost -= it->first;
            }
            else
            {
                cost -= arr[i];
            }
        }
        else
        {
            window.insert({arr[i], i});
            if (arr[i] < it->first)
            {
                cost -= arr[i];

                cost += it->first;
                it--;
                cost += it->first;
            }
            else
            {
                cost += arr[i];
            }
        }

        if (k % 2 == 1)
        {
            if (make_pair(arr[i - k], i - k) <= *it)
            {
                cost += arr[i - k];

                cost -= it->first;
                it++;
                cost -= it->first;
            }
            else
            {
                cost -= arr[i - k];
            }
            window.erase({arr[i - k], i - k});
        }
        else
        {
            if (make_pair(arr[i - k], i - k) >= *it)
            {
                cost -= arr[i - k];

                cost += it->first;
                it--;
                cost += it->first;
            }
            else
            {
                cost += arr[i - k];
            }
            window.erase({arr[i - k], i - k});
        }

        cout << cost - (k % 2 == 0 ? it->first : 0) << " ";
    }
    cout << endl;
}