#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXT 25000
#define INF 1000000000

struct metaEdge {
    int compIndex, start, stop, cost;
};

vector<pair<int, int> > roads[MAXT];
vector<metaEdge> planes[MAXT];
int costs[MAXT];
int component[MAXT], compCount = 0;

//floodfills components
void recurse(int node) {
    component[node] = compCount;
    for (auto next : roads[node]) {
        if (component[next.first] == -1) {
            recurse(next.first);
        }
    }
}

//creates toposort
vector<int> topoSort;
bool topoVisited[MAXT];
void dfs(int node) {
    topoVisited[node] = true;
    for (auto v : planes[node]) {
        if (!topoVisited[v.compIndex]) {
            dfs(v.compIndex);
        }
    }
    topoSort.push_back(node);
}

int main() {
    int t, r, p, s;
    cin >> t >> r >> p >> s;
    s--;

    int inp1, inp2, inp3;
    for (int i = 0; i < r; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp1--; inp2--;
        roads[inp1].push_back(make_pair(inp2, inp3));
        roads[inp2].push_back(make_pair(inp1, inp3));
    }

    //find component groups and label
    for (int i = 0; i < t; i++) {component[i] = -1;}
    for (int i = 0; i < t; i++) {
        if (component[i] == -1) {
            recurse(i);
            compCount++;
        }
    }

    //input into planes reversed, storing parent component, start town, end town, cost of flight
    for (int i = 0; i < p; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp1--; inp2--;
        metaEdge temp;
        temp.compIndex = component[inp1];
        temp.start = inp1;
        temp.stop = inp2;
        temp.cost = inp3;
        //planes is reversed, i.e. planes[i] gives the list of components that direct to i
        planes[component[inp2]].push_back(temp);
    }

    //create topological sort
    for (int i = 0; i < compCount; i++) {
        if (!topoVisited[i]) {
            dfs(i);
        }
        //no reverse needed
    }

    //initialize costs to inf
    for (int i = 0; i < t; i++) {
        costs[i] = INF;
    }

    //cost, node
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    pair<int, int> curTown;
    for (int curComp : topoSort) {
        for (auto edge : planes[curComp]) {
            if (costs[edge.start] != INF) {
                pq.push(make_pair(costs[edge.start] + edge.cost, edge.stop));
            }
        }
        while (!pq.empty()) {
            curTown = pq.top();
            pq.pop();
            if (costs[curTown.second] != INF)
                continue;
            costs[curTown.second] = curTown.first;
            for (auto edge : roads[curTown.second]) {
                if (costs[edge.first] == INF) {
                    //cout << edge.first << endl;
                    pq.push(make_pair(edge.second + curTown.first, edge.first));
                }
            }
        }
    }
    for (int i = 0; i < t; i++) {
        if (costs[i] == INF)
            cout << "NO PATH" << endl;
        else
            cout << costs[i] << endl;
    }
}
