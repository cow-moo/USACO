#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<string> visited;

int main()
{
    string num = "";
    for (int i = 0; i < 9; i++)
    {
        char x;
        cin >> x;
        num += x;
    }
    
    queue<pair<string, int>> q;
    q.push({num, 0});
    visited.insert(num);
    while (!q.empty())
    {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == "123456789")
        {
            //cout << visited.size() << endl;
            cout << dist << endl;
            return 0;
        }

        for (int i = 0; i < 9; i++)
        {
            if (i % 3 != 2)
            {
                string temp = cur;
                swap(temp[i], temp[i + 1]);
                if (visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    q.push({temp, dist + 1});
                }
            }
            if (i < 6)
            {
                string temp = cur;
                swap(temp[i], temp[i + 3]);
                if (visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    q.push({temp, dist + 1});
                }
            }
        }
    }
}