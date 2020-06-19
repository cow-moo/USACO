#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 100050
#define MAXB 100050

int depth[MAXN], snow[MAXB], dist[MAXB];
int tileId[MAXN], bootId[MAXB];
int next[MAXN], prev[MAXN];
int ans[MAXB];

bool tile_comp(int a, int b) { //thickest to thinnest snow
    return depth[a] > depth[b];
}

bool boot_comp(int a, int b) { //most to least heavy duty
    return snow[a] > snow[b];
}


int main() {
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    int n, b, curPos = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> depth[i];
        tileId[i] = i;
        next[i] = i + 1;
        prev[i] = i - 1;
    }
    for (int i = 0; i < b; i++) {
        cin >> snow[i] >> dist[i];
        bootId[i] = i;
    }

    sort(tileId, tileId + n, tile_comp);
    sort(bootId, bootId + b, boot_comp);

    int maxStep = 1, curTile = 0;
    for (int i = 0; i < b; i++) {
        while (curTile < n && depth[tileId[curTile]] > snow[bootId[i]]) {
            next[prev[tileId[curTile]]] = next[tileId[curTile]];
            prev[next[tileId[curTile]]] = prev[tileId[curTile]];
            maxStep = max(maxStep, next[tileId[curTile]] - prev[tileId[curTile]]);
            curTile++;
        }
        if (maxStep <= dist[bootId[i]]) {
            ans[bootId[i]] = 1;
        }
    }

    for (int i = 0; i < b; i++) {
        cout << ans[i] << endl;
    }
}
