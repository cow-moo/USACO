#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;
#define MAXN 100005

struct Point
{
    long long x, y;
    
    const bool operator< (const Point &r) const
    {
        return tie(x, y) < tie(r.x, r.y);
    }
} pts[MAXN], hull[MAXN];

long long dist2(Point a, Point b)
{
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

bool ccw(Point p1, Point p2, Point p3)
{
    return (p1.x - p2.x) * (p3.y - p2.y) >= (p3.x - p2.x) * (p1.y - p2.y);
}

bool ccwVect(int i, int j)
{
    return (hull[i + 1].x - hull[i].x) * (hull[j + 1].y - hull[j].y) > (hull[j + 1].x - hull[j].x) * (hull[i + 1].y - hull[i].y);
}

int main()
{
    cout << 1000000000.0 / sqrt(2) << endl;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts, pts + n);

    int sz = 0;
    for (int i = 0; i < n; i++)
    {
        while (sz > 1 && ccw(hull[sz - 2], hull[sz - 1], pts[i]))
            sz--;
        hull[sz++] = pts[i];
    }

    int botSz = --sz;
    for (int i = n - 1; i >= 0; i--)
    {
        while (sz - botSz > 1 && ccw(hull[sz - 2], hull[sz - 1], pts[i]))
            sz--;
        hull[sz++] = pts[i];
    }
    sz--;
    //reverse(hull, hull + sz);
    hull[sz] = hull[0];
    hull[sz + 1] = hull[1];

    // cout << endl;
    // for (int i = 0; i <= sz + 1; i++)
    // {
    //     cout << hull[i].x << " " << hull[i].y << endl;
    // }
    
    int j = 1;
    long long maxDist2 = 0;
    for (int i = 0; i <= sz; i++)
    {
        while (ccwVect(i, j))
        {
            j++;
            if (j >= sz)
                j -= sz;
        }
        maxDist2 = max(maxDist2, dist2(hull[i], hull[j]));
        maxDist2 = max(maxDist2, dist2(hull[i + 1], hull[j]));
        maxDist2 = max(maxDist2, dist2(hull[i], hull[j + 1]));
        maxDist2 = max(maxDist2, dist2(hull[i + 1], hull[j + 1]));
    }

    cout << setprecision(10) << fixed << sqrt(maxDist2) << endl;
}