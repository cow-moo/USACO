#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<pair<char, int> > agents;

int main()
{
    int t;
    cin >> t;
    cin.get();

    for (int z = 0; z < t; z++)
    {
        agents.clear();
        string line;
        getline(cin, line);
        //cout << line << endl;

        string inp;
        istringstream iss(line);
        while (iss >> inp)
        {
            cout << inp << endl;
            int temp;
            istringstream(inp.substr(2)) >> temp;
            agents.push_back({inp[0], temp});
        }

        sort(agents.begin(), agents.end());
        for (auto p : agents)
        {
            cout << p.first << " " << p.second << endl;
        }
    }
}
