#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
using namespace std;

vector<string> ballots;

map<char, int> votes;
map<char, bool> dq;

int main()
{
    cout << fixed << setprecision(1);

    int n;
    cin >> n;

    for (int z = 0; z < n; z++)
    {
        ballots.clear();

        int b, c;
        cin >> b >> c;

        int req = b / 2 + 1;

        for (int i = 0; i < b; i++)
        {
            string s;
            cin >> s;
            ballots.push_back(s);
        }

        int tallies = 0;
        while(true)
        {
            votes.clear();
            for (int i = 0; i < b; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (!dq[ballots[i][j]])
                    {
                        votes[ballots[i][j]]++;
                        break;
                    }
                }
            }
            tallies++;

            int minim = b;
            bool done = false;
            for (auto p : votes)
            {
                //cout << p.first << " " << p.second << endl;
                minim = min(minim, p.second);
                if (p.second >= req)
                {
                    cout << "Candidate " << p.first << " won with " << 100.0 * p.second / b << "% of the vote after " << tallies << " tallies" << endl;
                    done = true;
                    break;
                }
            }
            if (done)
                break;

            for (auto p : votes)
            {
                if (minim == p.second)
                {
                    dq[p.first] = true;
                }
            }

//            for (auto p : dq)
//            {
//                cout << p.first << " " << p.second << endl;
//            }
//            cout << endl;
        }
    }
}
