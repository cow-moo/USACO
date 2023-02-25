#include <iostream>
using namespace std;

bool occupied[205];
int pos[205];

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    for (int i = 0; i < k; i++)
    {
        cin >> pos[i];
        occupied[pos[i]] = true;
    }

    for (int i = 0; i < q; i++)
    {
        int l;
        cin >> l;
        l--;

        if (pos[l] == n)
            continue;
        if (occupied[pos[l] + 1])
            continue;
        occupied[pos[l]] = false;
        occupied[pos[l] + 1] = true;
        pos[l]++;
    }

    for (int i = 0; i < k; i++)
    {
        cout << pos[i] << " ";
    }
    cout << endl;
}