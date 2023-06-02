#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <map>
using namespace std;



int main() {
    string line;
    string entry = "";
    string cur = "";
    set<string> bugs;
    set<string> avail;
    map<string, vector<string>> adj;
    while (getline(cin, line)) {
        istringstream stream(line);
        if (line[0] == 'N') {
            string N,name;
            stream >> N >> name;
            if (entry == "") {
                entry = name;
            }
            cur = name;
            avail.insert(cur);
        } else {
            if (line.find("BUG") != string::npos) {
                bugs.insert(cur);
            } else {
                string UE, aa, v;
                stream >> UE >> aa >> v;
                adj[cur].push_back(v);
            }
        }
    }

    queue<string> q;
    map<string, int> dist;
    dist[entry] = 0;
    q.push(entry);
    map<string, string> prd;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        for (string v : adj[u]) {
            if (!dist.count(v)) {
                dist[v] = dist[u]+1;
                prd[v] = u;
                q.push(v);
            }
        }
    }
    int mn = 1e9;
    string dest;
    for (string s : bugs) {
        if (dist[s] < mn) {
            mn = dist[s];
            dest = s;
        }
    }
    vector<string> path;
    for (string cur = dest; cur != entry; cur = prd[cur]) {
        path.push_back(cur);
    }
    path.push_back(entry);
    reverse(begin(path), end(path));
    for (string node : path) {
        cout << node << "\n";
    }
}

/*
N B1
 UE -> B2
 UE -> B6
N B2
 UE -> B3
N B3
 UE -> B4
 UE -> B5
N B4
N B5
  BUG
  UE -> B4
N B6 
  UE -> B3
*/