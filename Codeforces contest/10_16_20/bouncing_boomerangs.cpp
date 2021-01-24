#include <iostream>
#include <vector>
using namespace std;

int bounces[100050];

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > ans;

    int count3 = 0, last1 = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> bounces[i];
        if (bounces[i] == 3)
            count3++;
        if (bounces[i] == 1)
            last1 = i;
    }

    int curRow = 1;
    int used2 = -1;
    bool last1Used = false;
    if (count3 > 0)
    {
        bool first3 = true;
        for (int i = 0; i < n; i++)
        {
            if (bounces[i] == 3)
            {
                if (first3)
                {
                    ans.push_back({curRow, i + 1});
                    first3 = false;
                }
                else
                {
                    ans.push_back({curRow++, i + 1});
                    ans.push_back({curRow, i + 1});
                }

                count3--;

                if (i > last1)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }

            if (count3 == 0 && bounces[i] == 2)
            {
                used2 = i;
            }
        }
        if (used2 == -1) //no 2 found
        {
            ans.push_back({curRow++, last1 + 1});
            ans.push_back({curRow++, last1 + 1});
        }
        else
        {
            ans.push_back({curRow++, used2 + 1});
            ans.push_back({curRow, used2 + 1});

            ans.push_back({curRow++, last1 + 1});
        }

        last1Used = true;
    }
    //cout << 'a' << last1 << endl;
    //int cnt = 0;
    //if (has2)
    //{
        //if (last1 == -1)
        //{
        //    cout << -1 << endl;
        //    return 0;
        //}
        int row1 = curRow, row2 = curRow;
        for (int i = n - 1; i >= 0; i--)
        {
            if (bounces[i] == 1 && !(i == last1 && last1Used))
            {
                ans.push_back({row1++, i + 1});
            }
            else if (bounces[i] == 2 && i != used2)
            {
                if (row2 < row1)
                {
                    ans.push_back({row2++, i + 1});
                }
                else
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    //}

    cout << ans.size() << endl;
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
