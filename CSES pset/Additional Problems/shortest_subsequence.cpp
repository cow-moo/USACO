#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> pos[4];
char chars[] = {'A', 'C', 'G', 'T'};

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
            case 'A':
                pos[0].push(i);
                break;
            case 'C':
                pos[1].push(i);
                break;
            case 'G':
                pos[2].push(i);
                break;
            case 'T':
                pos[3].push(i);
                break;
        }
    }
    string ans = "";
    int cur = -1;

    while (true)
    {
        int worst = 0;

        for (int i = 0; i < 4; i++)
        {
            while (!pos[i].empty() && cur >= pos[i].front())
                pos[i].pop();
            if (pos[i].empty())
            {
                cout << ans << chars[i] << endl;
                return 0;
            }
            else if (pos[i].front() > pos[worst].front())
            {
                worst = i;
            }
        }

        ans += chars[worst];
        cur = pos[worst].front();
    }
}