#include <iostream>
#include <map>
using namespace std;

struct State
{
    int rps[3] = {0, 0, 0};

    bool operator<(const State& rhs) const
    {
        for (int i = 0; i < 3; i++)
        {
            if (rps[i] < rhs.rps[i])
                return true;
            else if (rps[i] > rhs.rps[i])
                return false;
        }
        return false;
    }
};

int main()
{
    int t, x;
    cin >> t >> x;

    for (int z = 1; z <= t; z++)
    {
        int w, e;
        cin >> w >> e;
        cout << "Case #" << z << ": ";
        map<State, pair<float, string> > cur;
        map<State, pair<float, string> > next;
        State temp;
        temp.rps[0] = 1;
        cur[temp] = {(float)(w + e) / 3, "R"};
        string str = "RPS";
        for (int i = 1; i < 60; i++)
        {
            for (auto st : cur)
            {
                //cout << 'a';
                State newSt = st.first;
                for (int j = 0; j < 3; j++)
                {
                    newSt.rps[j]++;
                    if (!next.count(newSt))
                        next[newSt] = {0, ""};

                    float newVal = st.second.first + (float)(st.first.rps[(j + 2) % 3] * e + st.first.rps[(j + 1) % 3] * w) / i;
                    if (newVal > next[newSt].first)
                    {
                        next[newSt] = {newVal, st.second.second + str[j]};
                    }

                    newSt.rps[j]--;
                }
            }
            cur = next;
            next.clear();
            //cout << i;
        }
        cout << endl;

        pair<float, string> maxAns = {0, ""};
        for (auto st : cur)
        {
            if (st.second.first > maxAns.first)
                maxAns = st.second;
        }
        cout << maxAns.first << " " << maxAns.second << endl;
        //cout << eVal << endl;
    }
}
/*
4 0
60 0
Case #1:
1707.96 RPPPPPPPPPSSSSSSSSSSSSSSSSSSSSSSSSSSSRRRRRRRRRRRRRRRRRRRRRRR
60 6
Case #2:
1860.7 RPPPPPPPPPSSSSSSSSSSSSSSSSSSSSSSSSSSSRRRRRRRRRRRRRRRRRRRRRRR
60 30
Case #3:
2529.33 RRPPPPPPPPPPPPPPPPPPPPPPPPPSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
60 60
Case #4:
3580 RPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP
*/

/*
4 0
60 0
Case #1: RPPSSRRPPSSRRPPSSRRPPSSRRPPSSRRPPSSRRPPSSRRPPSSRRPPSSRRPPSSR
1353.07
60 6
Case #2: RPPSSSRRRPPPSSSRRRPPPSSSRRRPPPSSSRRRPPPSSSRRRPPPSSSRRRPPPSSS
1493.07
60 30
Case #3: RPPPSSSSSRRRRRRRPPPPPPPPPSSSSSSSSSSSRRRRRRRRRRRRRPPPPPPPPPPP
2097.89
60 60
Case #4: RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
3580
*/
