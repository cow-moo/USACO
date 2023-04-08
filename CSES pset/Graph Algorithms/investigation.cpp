#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100005
#define MOD 1000000007

struct Key
{
    long long dist;
    int dest;

    bool operator <(const Key &other) const
    {
        return dist < other.dist || (dist == other.dist && dest < other.dest);
    }
};

struct Value
{
    long long cnt;
    int low, high;
};

//distance, destination -> cnt, low, high
map<Key, Value> pq;
vector<Key> adj[MAXN];
bool visited[MAXN];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    Key init {0, 1};
    pq[init] = {1, 0, 0};
    while (!pq.empty())
    {
        auto [cur, v] = *pq.begin();
        pq.erase(pq.begin());
        
        if (cur.dest == n)
        {
            cout << cur.dist << " " << v.cnt << " " << v.low << " " << v.high << endl;
            return 0;
        }
        if (visited[cur.dest])
            continue;
        visited[cur.dest] = true;

        for (auto next : adj[cur.dest])
        {
            if (visited[next.dest])
                continue;
            Key newk = {cur.dist + next.dist, next.dest};
            auto it = pq.find(newk);
            if (it == pq.end())
            {
                pq[newk] = {v.cnt, v.low + 1, v.high + 1};
            }
            else
            {
                it->second.cnt += v.cnt;
                if (it->second.cnt >= MOD)
                    it->second.cnt -= MOD;
                it->second.low = min(it->second.low, v.low + 1);
                it->second.high = max(it->second.high, v.high + 1);
            }
        }
    }
}