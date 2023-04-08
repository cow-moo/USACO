#include <iostream>
#include <algorithm>
using namespace std;

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
};

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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Point p1, p2, p3, p4;
        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

        if (!sameSide(p1, p2, p3, p4) && !sameSide(p3, p4, p1, p2) && min(max(p1.x, p2.x), max(p3.x, p4.x)) >= max(min(p1.x, p2.x), min(p3.x, p4.x)) && min(max(p1.y, p2.y), max(p3.y, p4.y)) >= max(min(p1.y, p2.y), min(p3.y, p4.y)))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}