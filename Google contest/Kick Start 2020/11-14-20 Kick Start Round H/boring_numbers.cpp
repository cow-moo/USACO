#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long long boring_num(string x)
{
    int nums[20];
    bool alreadyLess = false;
    for (int i = 0; i < x.length(); i++)
    {
        if (alreadyLess)
        {
            nums[i] = 4;
        }
        else
        {
            //if even digit
            if ((i + 1) % 2 == 0)
            {
                if ((x[i] - '0') % 2 == 0)
                {
                    nums[i] = (x[i] - '0') / 2;
                }
                else
                {
                    nums[i] = (x[i] - '0' - 1) / 2;
                    alreadyLess = true;
                }
            }
            else
            {
                if ((x[i] - '0') % 2 == 1)
                {
                    nums[i] = (x[i] - '0' - 1) / 2;
                }
                else
                {
                    nums[i] = (x[i] - '0') / 2 - 1;
                    alreadyLess = true;
                }
            }
        }
        //cout << nums[i];
    }
    //cout << endl;
    //cout << x.length() << endl;
    long long ans = 1; //including 000
    long long exp = 1; //power of 5
    for (int i = x.length() - 1; i >= 0; i--)
    {
        ans += exp * nums[i];
        exp *= 5;
    }
    ans += (exp - 1) / 4 - 1;
    //cout << ans << " " << exp << endl;
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long l;
        string r;
        cin >> l >> r;
        stringstream temp;
        temp << (l - 1);
        string ltemp;
        temp >> ltemp;
        cout << "Case #" << z << ": " << boring_num(r) - boring_num(ltemp) << endl;

    }
}
