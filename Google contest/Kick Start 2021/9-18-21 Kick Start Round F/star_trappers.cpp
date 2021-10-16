#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
#include <stdio.h>
using namespace std;
#define INF 1000000000

struct Point
{
    long long x, y;

    Point() { x = 0, y = 0; }
    Point(long long x, long long y) { this->x = x, this->y = y; }

    Point operator-(const Point &other)
    {
        return Point(this->x - other.x, this->y - other.y);
    }

    static long long crossProduct(const Point &a, const Point &b)
    {
        return a.x * b.y - a.y * b.x;
    }

    bool operator==(const Point &other)
    {
        return this->x == other.x && this->y == other.y;
    }

    double length()
    {
        return sqrt(x * x + y * y);
    }
};
//n 1 0 2
bool sameSign(long long a, long long b)
{
    return (a > 0 && b > 0) || (a < 0 && b < 0);
}

bool sameSide(Point p1, Point p2, Point a, Point b)
{
    long long first = Point::crossProduct(b - a, p1 - a);
    long long second = Point::crossProduct(b - a, p2 - a);
    return sameSign(first, second);
}

bool pointInTriangle(Point p, Point a, Point b, Point c)
{
    return sameSide(p, a, b, c) && sameSide(p, b, a, c) && sameSide(p, c, a, b);
}

bool pointOnSegment(Point p, Point a, Point b)
{
    return Point::crossProduct(b - a, p - a) == 0 && ((sameSign(p.x - a.x, b.x - a.x) && (p.x - a.x) / (b.x - a.x) == 0) ||
                                                      (sameSign(p.y - a.y, b.y - a.y) && (p.y - a.y) / (b.y - a.y) == 0));
}

Point points[350];

int main()
{
    //freopen("test.txt", "r", stdin);
    cout << setprecision(10);

    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;

        for (int i = 0; i <= n; i++)
        {
            long long x, y;
            cin >> x >> y;
            points[i] = Point(x, y);
        }

//        if (z == 32)
//        {
//            cout << n << endl;
//            for (int i = 0; i <= n; i++)
//            {
//                cout << points[i].x << " " << points[i].y << endl;
//            }
//        }

        vector<pair<int, int> > including;

        double ans = INF;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (pointInTriangle(points[n], points[i], points[j], points[k]))
                    {
                        ans = min(ans, (points[i] - points[j]).length() + (points[j] - points[k]).length() + (points[k] - points[i]).length());
                    }
                }

                if (pointOnSegment(points[n], points[i], points[j]))
                {
                    including.push_back({i, j});
                }
            }
        }
        //cout << including.size() << endl;
        for (int i = 0; i < including.size(); i++)
        {
            for (int j = i + 1; j < including.size(); j++)
            {
                Point point1 = points[including[i].first];
                Point point2 = points[including[j].first];
                Point point3 = points[including[i].second];
                Point point4 = points[including[j].second];

                if (point1 == point2 || point1 == point3 || point1 == point4 || Point::crossProduct(point1 - point3, point2 - point4) == 0)
                    continue;
                ans = min(ans, (point1 - point2).length() + (point2 - point3).length() + (point3 - point4).length() + (point4 - point1).length());
            }
        }

        cout << "Case #" << z << ": ";
        if (ans == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;

        //cout << pointOnSegment(points[n], points[0], points[2]) << endl;
        //cout << pointInTriangle(points[n], points[0], points[1], points[2]) << endl;
        //cout << sameSide(points[n], points[1], points[0], points[2]) << endl;
    }
}


/*
4
3
0 0
6 0
6 8
3 5
3
0 0
1000000 0
0 1000000
5 7
2
0 0
5 0
2 2
3
0 0
5 0
0 5
1 1

1
3
0 0
2 1
1 2
1 1
*/
