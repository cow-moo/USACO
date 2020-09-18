#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        vector<int> ans;
        int n;
        cin >> n;

        int curZeroLength = 0;
        int oneCount = 0;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;

            if (inp == 1)
            {
                if (curZeroLength % 2 == 1 && oneCount != 0)
                {
                    ans.back() = 1;
                }
                else
                {
                    ans.push_back(1);
                }
                curZeroLength = 0;
                oneCount++;
            }
            else
            {
                ans.push_back(0);
                curZeroLength++;
            }
        }
        if (oneCount % 2 == 1)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == 1)
                {
                    ans.erase(ans.begin() + i);
                    break;
                }
            }
        }
        cout << ans.size() << endl;
        for (int a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }
}
