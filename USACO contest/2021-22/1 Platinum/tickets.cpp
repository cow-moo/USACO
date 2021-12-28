#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 100050
#define MAXK 100050

//parents
vector<pair<int, int> > parents[MAXK + MAXN];
vector<pair<pair<int, int>, pair<int, int> > > tickets;
long long dist[MAXK + MAXN];
pair<long long, bool> dist2[MAXK + MAXN];
//long long minOnPath[MAXK];

//0 is 1
//1 to k is tickets
//k + 1 is n
//k + 2 is 2
//k + n - 1 is n - 1

int main()
{
    //cout << "test1" << endl;
    int n, k;
    cin >> n >> k;


    tickets.push_back({{1, 0}, {0, 0}});
    for (int i = 1; i <= k; i++)
    {
        tickets.push_back({{0, 0}, {0, 0}});
        cin >> tickets[i].first.first >> tickets[i].first.second >> tickets[i].second.first >> tickets[i].second.second;
    }
    tickets.push_back({{n, 0}, {0, 0}});
    //tickets[0] = {{1, 0}, {0, 0}};
    //tickets[k + 1] = {{n, 0}, {0, 0}};

    //cout << "test2" << endl;
    sort(tickets.begin() + 1, tickets.end() - 1);
    //cout << "test2.5" << endl;
    for (int i = 1; i <= k; i++)
    {
        pair<pair<int, int>, pair<int, int> > temp = {{tickets[i].second.first, 0}, {0, 0}};
        auto it = lower_bound(tickets.begin(), tickets.end(), temp);
        while ((*it).first.first <= tickets[i].second.second && it != tickets.end())
        {
            //parents[it - tickets.begin()].push_back({i, tickets[i].first.second});
            parents[it - tickets.begin()].push_back({i, (*it).first.second});
            it++;
        }

        if (tickets[i].first.first == 1)
            parents[i].push_back({0, tickets[i].first.second});
        else if (tickets[i].first.first == n)
            parents[i].push_back({k + 1, tickets[i].first.second});
        else
            parents[i].push_back({k + tickets[i].first.first, tickets[i].first.second});
    }
    //cout << "test3" << endl;
//    for (int i = 0; i <= k + 1; i++)
//    {
//        for (auto p : parents[i])
//        {
//            cout << i << " " << p.first << " " << p.second << endl;
//        }
//    }

    for (int i = 0; i <= k + 4 + n; i++)
    {
        dist[i] = -1;
        dist2[i].first = -1;
    }
    dist[0] = 0;

    //cout << "test4" << endl;
    priority_queue<pair<long long, int> > pq;
    pq.push({0, 0});
    while (!pq.empty())
    {
        //cout << pq.size() << endl;
        int v = pq.top().second;
        long long d = -pq.top().first;
        pq.pop();
        if (dist[v] != d)
            continue;

        for (auto p : parents[v])
        {
            if (dist[p.first] == -1 || p.second + d < dist[p.first])
            {
                dist[p.first] = p.second + d;
                if (p.first <= k + 1)
                    pq.push({-dist[p.first], p.first});
            }
        }
    }

//    for (int i = 0; i <= k + 1; i++)
//    {
//        cout << dist[i] << endl;
//    }

    priority_queue<pair<pair<long long, long long>, int> > pq2;
    dist2[k + 1].first = 0;
    pq2.push({{0, -1}, k + 1});
    while (!pq2.empty())
    {
        //cout << pq2.size() << endl;
        int v = pq2.top().second;
        long long d = -pq2.top().first.first;
        //min dist to one on the path
        long long minToOne = pq2.top().first.second;
        pq2.pop();
        if (dist2[v].first != d || dist2[v].second != (minToOne != -1))
            continue;

        long long minToN = d - (minToOne == -1 ? 0 : minToOne);
        //cout << v << " " << minToN << " " << minToOne << endl;
        for (auto p : parents[v])
        {
            //long long newMinToOne = minToOne == -1 ? dist[p.first] : min(dist[p.first], minToOne);
            long long newMinToN = minToN + p.second;
            long long newMinToOne = minToOne;
            if ((minToOne == -1 && dist[p.first] != -1) || minToOne > dist[p.first])
            {
                newMinToOne = dist[p.first];
            }


            //if (newMinToOne == -1)
            //{
            //    newDist = -(d + p.second);
            //}
            //else
            //{
            //    newDist = (minToOne == -1 ? d : d - minToOne) + p.second + newMinToOne;
            //}
            if (dist2[p.first].first == -1 || (newMinToOne != -1 && dist2[p.first].second == false) || newMinToN + (minToOne == -1 ? 0 : minToOne) < dist2[p.first].first)
            {
                dist2[p.first].first = newMinToN + (newMinToOne == -1 ? 0 : newMinToOne);
                dist2[p.first].second = newMinToOne != -1;
                if (p.first <= k + 1)
                    pq2.push({{-dist2[p.first].first, newMinToOne}, p.first});
//                else
//                {
//                    cout << p.first - (k) << " " << newMinToN << " " << newMinToOne << endl;
//                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        //cout << dist[k + 1 + i] << endl;
        cout << (dist2[k + 1 + i].second ? dist2[k + 1 + i].first : -1) << endl;
    }
/*
//    for (int i = 1; i <= k; i++)
//    {
//        if (dist2[i].second)
//        {
//            if (ans[tickets[i].first.first] == -1)
//            {
//                ans[tickets[i].first.first] = dist2[i].first + tickets[i].first.second;
//            }
//            else
//            {
//                ans[tickets[i].first.first] = min(ans[tickets[i].first.first], dist2[i].first + tickets[i].first.second);
//            }
//        }
//    }
//
//    for (int i = 1; i <= n; i++)
//    {
//        cout << ans[i] << endl;
//    }
*/
}
