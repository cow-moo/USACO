#include <iostream>
using namespace std;

int n, m;

bool corner(int x1, int y1)
{
    return (x1 == 1 || x1 == n) && (y1 == 1 || y1 == m);
}

bool edge(int x1, int y1)
{
    return x1 == 1 || x1 == n || y1 == 1 || y1 == m;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (corner(x1, y1) || corner(x2, y2))
        {
            cout << 2 << endl;
        }
        else if (edge(x1, y1) || edge(x2, y2))
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 4 << endl;
        }
    }
}