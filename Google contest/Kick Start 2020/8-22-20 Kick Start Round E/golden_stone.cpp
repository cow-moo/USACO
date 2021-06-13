#include <iostream>
#include <vector>
using namespace std;

int n;

//vector<int> adj[305];
long long dist[305][305];
//locations[i] is list of junctions where you can find stone i
vector<int> locations[305];
//recipes[i] is list of recipes of stone i
vector<vector<int> > recipes[305];
long long energy[305][305];

long long minEnergy(int stone, int junction) {
//    if (energy[stone][junction] != -1) {
//        return energy[stone][junction];
//    }
    long long result = 1000000000000;
    for (int j : locations[stone]) {
        result = min(result, (long long) dist[j][junction]);
    }

    for (vector<int> recipe : recipes[stone]) {
        for (int i = 1; i <= n; i++) {
            long long curDist = dist[i][junction];
//            if (dist[i][junction] >= result)
//                continue;
            for (int st : recipe) {
                if (curDist >= result)
                    break;
                curDist += minEnergy(st, i);
            }
            result = min(result, curDist);
        }
    }

    //energy[stone][junction] = result;
    return result;
}

int main() {
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++) {
        int m, s, r;
        cin >> n >> m >> s >> r;

        for (int i = 1; i <= s; i++) {
            for (int j = 1; j <= n; j++) {
                energy[i][j] = -1;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                dist[i][j] = 1000000;
                dist[j][i] = 1000000;
            }
        }

        for (int i = 0; i < m; i++) {
//            cin >> inp1 >> inp2;
//            adj[inp1].push_back(inp2);
//            adj[inp2].push_back(inp1);
            int u, v;
            cin >> u >> v;
            dist[u][v] = 1;
            dist[v][u] = 1;
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

//        cout << endl;
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cout << i << " " << j << ": " << dist[i][j] << endl;;
//            }
//        }
//        cout << endl;

        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            for (int j = 0; j < c; j++) {
                int stone;
                cin >> stone;
                locations[stone].push_back(i);
            }
        }

//        for (int i = 1; i <= s; i++) {
//            cout << i << ": ";
//            for (int j : locations[i]) {
//                cout << j << " ";
//            }
//            cout << endl;
//        }

        for (int i = 0; i < r; i++) {
            int k;
            cin >> k;
            vector<int> recipe;
            for (int j = 0; j < k; j++) {
                int stone;
                cin >> stone;
                recipe.push_back(stone);
            }
            int result;
            cin >> result;
            recipes[result].push_back(recipe);
        }

        long long ans = 1000000000000;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, minEnergy(1, i));
        }
        cout << "Case #" << z << ": ";
        if (ans == 1000000000000) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}
