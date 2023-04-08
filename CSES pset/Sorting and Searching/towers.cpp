#include <iostream>
#include <set>
using namespace std;

multiset<int> towers;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        auto it = towers.upper_bound(k);
        if (it == towers.end())
        {
            towers.insert(k);
        }
        else
        {
            towers.erase(it);
            towers.insert(k);
        }
    }
    
    cout << towers.size() << endl;
}