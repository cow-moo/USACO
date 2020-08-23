#include <iostream>
using namespace std;

int nums[1005];
int cnts[1005];
bool used[1005];

int ans[2005];
int anscnt = 0;

int main() {
    int t;
    cin >> t;

    for (int z = 0; z < t; z++) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> nums[i];
            cnts[nums[i]]++;
        }

        while (true) {
            int mex;
            for (int i = 0; i <= n; i++) {
                if (cnts[i] == 0) {
                    mex = i;
                    break;
                }
            }
            if (mex == 0) {
                for (int i = 1; i <= n; i++) {
                    if (!used[i]) {
                        //cout << i << " ";
                        ans[anscnt++] = i;
                        cnts[nums[i]]--;
                        cnts[0]++;
                        nums[i] = 0;
                        break;
                    }
                }
                if (cnts[0] == 0)
                    break;
            }
            else {
                //cout << mex << " ";
                ans[anscnt++] = mex;
                cnts[nums[mex]]--;
                cnts[mex]++;
                nums[mex] = mex;
                used[mex] = true;
            }
        }
        cout << anscnt << endl;
        for (int i = 0; i < anscnt; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;

        for (int i = 0; i <= n; i++) {
            cnts[i] = 0;
            nums[i] = 0;
            used[i] = false;
        }
        anscnt = 0;
    }
}


