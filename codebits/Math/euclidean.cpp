#include <iostream>
using namespace std;

pair<long long, long long> euclidean(long long a, long long b)
{
    pair<long long, long long> pa = {1, 0}, pb = {0, 1};
    if (a < b)
        swap(a, b), swap(pa, pb);
    while (b != 0)
    {
        long long q = a / b;
        a -= q * b;
        pa.first -= q * pb.first;
        pa.second -= q * pb.second;
        swap(a, b), swap(pa, pb);
    }
    return pa;
}

int main()
{
    long long a, b;
    cin >> a >> b;

    pair<long long, long long> res = euclidean(a, b);
    cout << res.first << " " << res.second << ": " << a * res.first + b * res.second << endl;
}