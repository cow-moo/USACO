#include <iostream>
#include <vector>
//#include <bitset>
using namespace std;
#define MOD 1000000007

long long dp[1050][1050];
vector<int> masks;
int n, m;

void recurse(int val, int pos)
{
    masks.push_back(val);
    for (int i = pos; i < n - 1; i++)
    {
        recurse(val + (1 << i) + (1 << (i + 1)), i + 2);
    }
}

int main()
{
    cin >> n >> m;

    recurse(0, 0);

//    for (int val : masks)
//    {
//        cout << bitset<6>(val) << endl;
//    }
    //cout << masks.size() << endl;

    dp[0][(1 << n) - 1] = 1;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = dp[i - 1][(1 << n) - 1];
        for (int j = 1; j < (1 << n); j++)
        {
            for (int mask : masks)
            {
                //cout << (mask & j) << ", " << mask << endl;
                if ((mask & j) == mask)
                {
                    //cout << mask << endl;
                    dp[i][j] += dp[i - 1][mask ^ j ^ ((1 << n) - 1)];
                    if (dp[i][j] >= MOD)
                        dp[i][j] -= MOD;
                }
            }
            //cout << i << " " << bitset<3>(j) << ": " << dp[i][j] << endl;
        }
    }
    cout << dp[m][(1 << n) - 1] << endl;
}



//1101001101
//1111111111

//0000000000
//0010110010

//0000000000
//1110110010

//0000000000
//0010111110

//0000000000
//1110111110


//1111111111
//0011111111
//1111110011
//0011110011

//1101100000

//1101001101
//0010110010
//1110110010
//0010111110
//1110111110
