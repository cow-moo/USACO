#include <iostream>
#include <vector>
using namespace std;

vector<int> soln;

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, x, y;
        cin >> n >> x >> y;

        cout << "Case #" << z <<": ";

        long long sum = n * (n + 1) / 2;
        if (sum % (x + y) != 0)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        long long alanSum = sum / (x + y) * x;
        soln.clear();
        for (int i = n; i >= 1; i--)
        {
            if (alanSum > i)
            {
                soln.push_back(i);
                alanSum -= i;
            }
            else
            {
                soln.push_back(alanSum);
                break;
            }
        }

        cout << "POSSIBLE" << endl;
        cout << soln.size() << endl;
        for (int s : soln)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}
