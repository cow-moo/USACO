#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000

vector<pair<int, int> > adj[1005]; //edge, cost
int minCost[1005][1005]; //minCost[i][j] is minimum max cost of telephone poles used to reach pole i while not paying for j poles
//is also visited array
int main() {
    int n, p, k;
    cin >> n >> p >> k;

    int inp1, inp2, inp3;
    for (int i = 0; i < p; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp1--;
        inp2--;
        adj[inp1].push_back(make_pair(inp2, inp3));
        adj[inp2].push_back(make_pair(inp1, inp3));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            minCost[i][j] = INF;
        }
    }

    //<-cost, <node, freeCount> >
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(0, 0)));

    while (!pq.empty()) {
        int node = pq.top().second.first;
        int freeCount = pq.top().second.second;
        if (minCost[node][freeCount] != INF){
            pq.pop();
            continue;
        }
        minCost[node][freeCount] = -pq.top().first;
        pq.pop();

        if (node == n - 1) {
            cout << minCost[node][freeCount] << endl;
            return 0;
        }

        for (pair<int, int> edge : adj[node]) {
            //cout <<"what"<<endl;
            //if new edge has less cost than max, don't try making it free
            if (edge.second <= minCost[node][freeCount]) {
                pq.push(make_pair(-minCost[node][freeCount], make_pair(edge.first, freeCount)));
            }
            //if new edge has more cost than max, try making it free and not making it free
            else {
                pq.push(make_pair(-edge.second, make_pair(edge.first, freeCount)));
                if (freeCount < k) {
                    pq.push(make_pair(-minCost[node][freeCount], make_pair(edge.first, freeCount + 1)));
                }
                //cout << "r" <<endl;
            }
        }
    }

    cout << -1 << endl;
}
