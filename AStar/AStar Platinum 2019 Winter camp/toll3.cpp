#include <iostream>
#include <algorithm>
using namespace std;
#define INF 1000000000

int adj[255][255];
int pastureToll[255];
int order[255];
int dist[255][255];
bool visited[255];
//min dist from i to j

bool comp(int a, int b) {
    return pastureToll[a] < pastureToll[b];
}

int main() {
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> pastureToll[i];
        order[i] = i;
    }

    sort(order, order + n, comp);
    sort(pastureToll, pastureToll + n);

//    for (int i = 0; i < n; i++) {
//        cout << order[i] << endl;
//    }

    int temp[255];
    for (int i = 0; i < n; i++) {
        temp[order[i]] = i;
    }

    int inp1, inp2, inp3;
    for (int i = 0; i < m; i++) {
        cin >> inp1 >> inp2 >> inp3;
        inp1--; inp2--;
        inp1 = temp[inp1];
        inp2 = temp[inp2];
        //cout << inp1 << " " << inp2 << endl;
        //cout << inp1 << " " << inp2 << endl;
        if (adj[inp1][inp2] == 0 || inp3 < adj[inp1][inp2]) {
            adj[inp1][inp2] = inp3;
            adj[inp2][inp1] = inp3;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n ; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++) {
        //reset visited
        for (int j = 0; j <= i; j++) {
            visited[j] = false;
        }
        dist[i][i] = pastureToll[i];
        //dijkstra from i
        for (int j = 0; j <= i; j++) {
            int minIndex = n;
            //find min cost cow
            for (int k = 0; k <= i; k++) {
                if (!visited[k] && dist[i][k] < dist[i][minIndex])
                    minIndex = k;
            }
            visited[minIndex] = true;
            //check adjacent nodes using 0 to i
            for (int k = 0; k <= i; k++) {
                if (adj[minIndex][k] != 0) {
                    dist[i][k] = min(dist[i][k], dist[i][minIndex] + adj[minIndex][k]);
                    dist[k][i] = dist[i][k];
                }
            }
        }

        for (int j = 0; j < i - 1; j++) {
            for (int k = j + 1; k < i; k++) {
                dist[j][k] = min(dist[j][k], dist[i][j] + dist[i][k] - pastureToll[i]);
                dist[k][j] = dist[j][k];
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << dist[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    for (int i = 0; i < k; i++) {
        cin >> inp1 >> inp2;
        inp1 = temp[inp1 - 1];
        inp2 = temp[inp2 - 1];
        //cout << inp1 << " " << inp2 << endl;
        cout << dist[inp1][inp2] << endl;
    }
}



