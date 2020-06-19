#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int k, seqCount = 0, maxim = 0;
        string students;
        cin >> k >> students;
        int it = 0;
        for (; it < k; it++) {
            if (students[it] == 'A')
                break;
        }
        //cout << it << endl;
        for (; it < k; it++) {
            //cout << students[it];
            if (students[it] == 'P') {
                seqCount++;
                //cout << it << endl;
            }
            else {
                maxim = max(maxim, seqCount);
                seqCount = 0;
            }
        }
        maxim = max(maxim, seqCount);
        cout << maxim << endl;
    }
}
