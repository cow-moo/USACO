#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sum[i] is sum of first i num
long long sum[5005];
vector<pair<long long, pair<int, int> > > sections;

int getLength(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        swap(a, b);

    if (a.second >= b.first)
        return -1;
    else
        return a.second - a.first + 1 + b.second - b.first + 1;
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        long long n, k;
        cin >> n >> k;

        //cin >> sum[0];
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            long long cur;
            cin >> cur;
            sum[i] = sum[i - 1] + cur;
        }

        sections.clear();
        for (int i = 0; i < n; i++)
        {
            if (sum[i + 1] - sum[i] == 0)
                continue;
            for (int j = i; j < n; j++)
            {
                if (sum[j + 1] - sum[j] == 0 || sum[j + 1] - sum[i] > k)
                    continue;
                sections.push_back({sum[j + 1] - sum[i], {i, j}});
            }
        }
        sections.push_back({0, {-1, -2}});
        sort(sections.begin(), sections.end());
//        for (int i = 0; i < sections.size(); i++)
//        {
//            cout << sections[i].first << " " << sections[i].second.first << " " << sections[i].second.second << endl;
//        }
        long long ans = -1;

        long long l = 0, r = sections.size() - 1;
        while (l < r)
        {
            if (sections[l].first + sections[r].first > k)
            {
                r--;
            }
            else if (sections[l].first + sections[r].first < k)
            {
                l++;
            }
            else
            {
//                if (ans != -1 && getLength(sections[l].second, sections[0].second) + (sections[l].first == k ? 0 : 1) >= ans)
//                {
//                    l++;
//                    continue;
//                }
//                for (int i = r; i > l; i--)
//                {
//                    if (sections[i].first != sections[r].first)
//                        break;
//
//                    long long length = getLength(sections[l].second, sections[i].second);
//                    //cout << sections[l].second.first << " " << sections[l].second.second << ", " << sections[i].second.first << " " << sections[i].second.second << ": " << sections[l].first + sections[i].first << " " << length << endl;
//                    if (length != -1 && (ans == -1 || length < ans))
//                    {
//                        ans = length;
//                    }
//                    if (length == -1)
//                        break;
//                }
//
//                l++;
                long long length = getLength(sections[l].second, sections[r].second);
                if (length != -1 && (ans == -1 || length < ans))
                {
                    ans = length;
                }
                if (sections[l].first == sections[l + 1].first)
                    l++;
                else if (sections[r].first == sections[r - 1].first)
                    r--;
                else
                    l++;
            }
        }

        cout << "Case #" << z << ": " << ans << endl;
    }
}
