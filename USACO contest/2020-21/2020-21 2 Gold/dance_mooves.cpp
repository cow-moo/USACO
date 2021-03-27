#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;

//positions visitable by i in each cycle
set<int> possible[100050];
pair<int, int> swaps[200050];
int cows[100050];
int visitCount[100050];

//post swap pos
int postSwapPos[100050];

int main()
{
    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
    {
        cows[i] = i;
        possible[i].insert(i);
    }

    for (int i = 0; i < k; i++)
    {
        cin >> swaps[i].first >> swaps[i].second;
        swaps[i].first--;
        swaps[i].second--;

        swap(cows[swaps[i].first], cows[swaps[i].second]);

        possible[cows[swaps[i].second]].insert(swaps[i].second);
        possible[cows[swaps[i].first]].insert(swaps[i].first);
    }

    for (int i = 0; i < n; i++)
    {
        postSwapPos[cows[i]] = i;
        cout << cows[i] << " " << i << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (visitCount[i] == 0)
        {
            vector<int> curCycle;
            map<int, int> uniquePos;

            int curPos = i;
            do
            {
                for (int pos : possible[curPos])
                {
                    uniquePos[pos]++;
                }
                curCycle.push_back(curPos);
                curPos = postSwapPos[curPos];
            } while (curPos != i);

            //cout << curCycle.size() << "a" << endl;
            for (int cow : curCycle)
            {
                visitCount[cow] = uniquePos.size();
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << visitCount[i] << endl;
    }
}
