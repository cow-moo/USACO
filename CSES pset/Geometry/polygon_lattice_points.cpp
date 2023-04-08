#include <iostream>
using namespace std;

struct Point
{
    long long x, y;
};

long long gcd(long long a, long long b)
{
    if (a > b)
        swap(a, b);
    if (a == 0)
        return b;
    return gcd(a, b - b / a * a);
}

int main()
{
    int n;
    cin >> n;

    Point prev, cur, initial;
    long long area = 0;
    long long boundary = 0;
    cin >> initial.x >> initial.y;
    prev = initial;
    for (int i = 1; i < n; i++)
    {
        cin >> cur.x >> cur.y;
        area += cur.y * prev.x - cur.x * prev.y;
        boundary += gcd(abs(cur.x - prev.x), abs(cur.y - prev.y));
        prev = cur;
    }
    area += initial.y * cur.x - initial.x * cur.y;
    boundary += gcd(abs(initial.x - cur.x), abs(initial.y - cur.y));
    cout << (abs(area) + 2 - boundary) / 2 << " " << boundary << endl;
}

//2 * area = 2 * inside + boundary - 2