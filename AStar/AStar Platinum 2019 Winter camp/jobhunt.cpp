#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000000

vector<pair<pair<int, int>, int> > edges;
int dist[250];

int main() {
    int d, p, c, f, s;
    cin >> d >> p >> c >> f >> s;
    s--;

    int inp1, inp2, inp3;
    for (int i = 0; i < p; i++) {
        cin >> inp1 >> inp2;
        edges.push_back({{inp1 - 1, inp2 - 1}, -d});
    }
    for (int i = 0; i < f; i++) {
        cin >> inp1 >> inp2 >> inp3;
        edges.push_back({{inp1 - 1, inp2 - 1}, -d + inp3});
    }

    for (int i = 0; i < c; i++) {
        dist[i] = INF;
    }
    dist[s] = -d;

    bool any;
    for (int i = 0; i < c; i++) {
        any = false;
        for (auto edge : edges) {
            if (dist[edge.first.first] < INF) {
                if (dist[edge.first.second] > dist[edge.first.first] + edge.second) {
                    dist[edge.first.second] = dist[edge.first.first] + edge.second;
                    any = true;
                }
            }
        }
    }

    if (any) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < c; i++) {
        ans = min(ans, dist[i]);
        //cout << dist[i] << endl;
    }

    cout << -ans << endl;
}
