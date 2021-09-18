#include <iostream>
using namespace std;

bool roads[10050];

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> roads[i];
        }

        if (roads[1] == true)
        {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else if (roads[n] == false)
        {
            for (int i = 1; i <= n + 1; i++)
                cout << i << " ";
            cout <<  endl;
        }
        else
        {
            bool done = false;
            for (int i = 1; i <= n; i++)
            {
                cout << i << " ";
                if (done == false && roads[i] == false && roads[i + 1] == true)
                {
                    cout << n + 1 << " ";
                    done = true;
                }
            }
            cout << endl;
        }
    }
}
