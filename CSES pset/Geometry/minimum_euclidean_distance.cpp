#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 200005

struct Point
{
    long long x, y;

    const bool operator<(const Point &r) const
    {
        return x < r.x || (x == r.x && y < r.y);
    }
} pts[MAXN];

bool comp(const Point &a, const Point &b)
{
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

long long dist(const Point &a, const Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long minDist(int l, int r)
{
    if (l + 1 == r)
        return dist(pts[l], pts[r]);
    else if (l + 2 == r)
        return min(min(dist(pts[l], pts[l + 1]), dist(pts[l], pts[l + 2])), dist(pts[l + 1], pts[l + 2]));

    int m = (l + r) / 2;
    long long d = min(minDist(l, m), minDist(m + 1, r));

    vector<Point> strip;
    for (int i = m; i >= l; i--)
    {
        if ((pts[m].x - pts[i].x) * (pts[m].x - pts[i].x) >= d)
            break;
        strip.push_back(pts[i]);
    }
    for (int i = m + 1; i <= r; i++)
    {
        if ((pts[m].x - pts[i].x) * (pts[m].x - pts[i].x) >= d)
            break;
        strip.push_back(pts[i]);
    }
    sort(strip.begin(), strip.end(), comp);

    for (int i = 0; i < strip.size(); i++)
    {
        for (int j = i + 1; j < strip.size(); j++)
        {
            if ((strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) >= d)
                break;

            d = min(d, dist(strip[i], strip[j]));
        }
    }
    return d;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts, pts + n);

    cout << minDist(0, n - 1) << endl;
}