#include <iostream>
#include <map>
using namespace std;

map<int, pair<int, int> > xCoords;
map<int, pair<int, int> > yCoords;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int k;
        cin >> k;

        xCoords.clear();
        yCoords.clear();
        for (int i = 0; i < k; i++)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            xCoords[x1].first++;
            xCoords[x2].second++;
            yCoords[y1].first++;
            yCoords[y2].second++;
        }

        int xAns, yAns;
        int l = 0, r = k;
        for (auto p : xCoords)
        {
            r -= p.second.first;
            l += p.second.second;

            if (l >= r)
            {
                xAns = p.first;
                break;
            }
        }

        l = 0, r = k;
        for (auto p : yCoords)
        {
            r -= p.second.first;
            l += p.second.second;

            if (l >= r)
            {
                yAns = p.first;
                break;
            }
        }

        cout << "Case #" << z << ": " << xAns << " " << yAns << endl;
    }
}
