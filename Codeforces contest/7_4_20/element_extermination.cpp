#include <iostream>
using namespace std;

int q[300050];

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        int index = 0, inp, first;
        for (int i = 0; i < n; i++) {
            cin >> inp;
            if (i == 0)
                first = inp;
            while (index > 0 && inp > q[index - 1])
                index--;
            q[index++] = inp;
        }
        cout << ((first < q[index - 1]) ? "YES" : "NO") << endl;
    }
}
