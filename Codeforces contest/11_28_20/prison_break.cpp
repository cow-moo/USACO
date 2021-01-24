#include <iostream>
using namespace std;

void solve()
{
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    cout << max(r - 1, n - r) + max(c - 1, m - c) << endl;
}

int main()
{
   int t;
   cin >> t;

   for (int i = 0; i < t; i++)
   {
       solve();
   }
}
