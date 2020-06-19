#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 200050

int parent[MAXN];
int ranks[MAXN];
int parentSet[MAXN]; //stores parent set leader index at set leader index
//each set should only have 1 parent set, or else those can be merged
int color[MAXN]; //color of each set at leader index

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b])
            swap(a, b);
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

vector<int> admirers[MAXN];

int main() {
    freopen("fcolor.in", "r", stdin);
    //freopen("fcolor.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
        parentSet[i] = -1;
    }

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        admirers[a - 1].push_back(b - 1);
        parentSet[a - 1] = b - 1;
    }
/*
    //for (int a = 0; a < 5; a++) {
    for (int i = 0; i < n; i++) {
        int leader = find_set(i);
        //if (parentSet[leader] == i)
        //    continue;
        for (int admirer : admirers[i]) {
            //if (find_set(admirer) != parentSet[leader]) {
                union_sets(admirer, parentSet[leader]); //admirer joins parent set
                parentSet[leader] = find_set(admirer); //parentSet set to the leader of that set (in case it was changed)
            //}
            //else {
            //    parentSet[i] = admirer;
            //}
        }
    }
    //}
*/
//    for (int i = 0; i < n; i++) {
//        cout << find_set(i) << endl;
//    }

//for (int i = 0; i < n; i++)
    //cout << parentSet[i] << endl;

    bool change;
    do {
    //for (int a = 0; a < 5; a++) {
        change = false;
        for (int i = 0; i < n; i++) {
            for (int admirer : admirers[i]) {
                if (find_set(admirer) != parentSet[find_set(i)]) {
                    union_sets(admirer, parentSet[find_set(i)]); //admirer joins parent set
                    parentSet[find_set(i)] = find_set(admirer); //parentSet set to the leader of that set (in case it was changed)
                    change = true;
                }
            }
        }
    } while (change);

    int curColor = 1;
    for (int i = 0; i < n; i++) {
        if (color[find_set(i)] == 0)
            color[find_set(i)] = curColor++;
        cout << color[find_set(i)] << endl;
    }
}
