#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<string> visited;

//i < j
string swap(string x, int i, int j)
{
    return x.substr(0, i) + x[j] + x.substr(i + 1, j - i - 1) + x[i] + x.substr(j + 1);
}

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
            cout << dist << endl;
            return 0;
        }

        for (int i = 0; i < 9; i++)
        {
            if (i % 3 != 2)
            {
                string temp = swap(cur, i, i + 1);
                if (visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    q.push({temp, dist + 1});
                }
            }
            if (i < 6)
            {
                string temp = swap(cur, i, i + 3);
                if (visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    q.push({temp, dist + 1});
                }
            }
        }
    }
}