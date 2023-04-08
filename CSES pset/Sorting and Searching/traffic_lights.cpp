#include <iostream>
#include <set>
using namespace std;

set<int> lights;
multiset<int> lengths;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;

        auto it = lights.insert(p).first;
        int r = *(++it);
        int l = *(----it);

        lengths.erase(lengths.find(r - l));
        lengths.insert(p - l);
        lengths.insert(r - p);

        cout << *lengths.rbegin() << " ";
    }
    cout << endl;
}