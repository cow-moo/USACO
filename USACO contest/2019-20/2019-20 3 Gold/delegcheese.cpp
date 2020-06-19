#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100050

int degrees[MAXN];
bool possible[MAXN];

int main() {
    freopen("deleg.in", "r", stdin);
    freopen("deleg.out", "w", stdout);

    int n;
    cin >> n;

    int inp1, inp2;
    for (int i = 0; i < n; i++) {
        cin >> inp1 >> inp2;
        //adj[inp1 - 1].push_back(inp2 - 1);
        //adj[inp2 - 1].push_back(inp1 - 1);
        degrees[inp1 - 1]++;
        degrees[inp2 - 1]++;
    }

    int odd = 0;
    for (int i = 0; i < n; i++) {
        if (degrees[i] % 2 == 1)
            odd++;
    }

    odd /= 2;

    //cout << odd << endl;
    possible[1] = 1;
    for (int i = odd; i <= n / 2; i++) {
        if ((n - 1) % i == 0) {
            possible[(n - 1) / i] = 1;
            //cout << (n - 1) / i << endl;
        }
    }

    for (int i = 1; i < n; i++)
        cout << possible[i];
    cout << endl;
}

