#include <iostream>
#include <map>
#include <stack>
using namespace std;

map<long long, stack<int>> nums;

int main()
{
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        nums[a].push(i);
    }

    for (auto it1 = nums.begin(); it1 != nums.end(); it1++)
    {
        int temp1 = it1->second.top();
        it1->second.pop();
        for (auto it2 = nums.lower_bound(x - it1->first - nums.rbegin()->first); it2 != nums.end(); it2++)
        {
            if (it2->second.size() == 0)
                continue;
            int temp2 = it2->second.top();
            it2->second.pop();

            auto it = nums.find(x - it1->first - it2->first);
            if (it != nums.end() && it->second.size() > 0)
            {
                cout << temp1 << " " << temp2 << " " << it->second.top() << endl;
                return 0;
            }

            it2->second.push(temp2);

            if (x - it1->first - it2->first < it2->first)
                break;
        }
        (it1->second).push(temp1);
    }
    cout << "IMPOSSIBLE" << endl;
}