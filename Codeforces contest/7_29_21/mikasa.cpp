#include <iostream>
#include <bitset>
using namespace std;

int main()
{
//    cout << bitset<32>(69) << endl << bitset<32>(696) << endl;
//    cout << bitset<32>(69 ^ 696) << endl << bitset<32>(640) << endl;
//    cout << endl;
//    cout << bitset<32>(123456) << endl << bitset<32>(654321) << endl;
//    cout << bitset<32>(123456 ^ 654321) << endl << bitset<32>(530866) << endl;
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n, m;
        cin >> n >> m;

        bitset<32> a(n);
        bitset<32> b(m);
        bitset<32> ans(0);
        //cout << a << endl;
        //cout << b << endl;

        bool use0 = false;
        for (int i = 31; i >= 0; i--)
        {
            if (a[i] == 1 && b[i] == 0)
            {
                use0 = true;
                break;
            }
            //cout << a[i] << " " << b[i] << " " << (a[i] ^ b[i]) << endl;

            ans[i] = a[i] ^ b[i];
        }

        //cout << ans << endl;

        if (!use0)
        {
            for (int i = 0; i < 32; i++)
            {
                if (a[i] == 0 && b[i] == 0)
                {
                    ans[i] = 1;
                    break;
                }
                else
                    ans[i] = 0;
            }
        }

        cout << ans.to_ullong() << endl;
//        cout << ((n ^ m) | n) << endl;
//        cout << bitset<32>(n) << endl;
//        cout << bitset<32>(m) << endl;
//        cout << bitset<32>(n ^ m) << endl;
    }
}
