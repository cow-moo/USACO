#include <iostream>
#include <vector>
#include <map>
using namespace std;

//struct Shape {
//    vector<pair<int, int> > verts;
//};

vector<pair<int, int> > shapes[400];
//number of shapes that enclose this shape
int encloseCount[400];
//cow counter
int countInside[400];

bool is_enclosed(vector<pair<int, int> > const &verts, pair<int, int> point) {
    int intersectCount = 0;

    //extend ray vertically and count intersections
    for (int i = 0; i < verts.size() - 1; i++) {
        //point.x must be >= l.first and < r.first
        pair<int, int> l, r;
        if (verts[i].first < verts[i + 1].first) {
            l = verts[i]; r = verts[i + 1];
        }
        else if (verts[i].first > verts[i + 1].first) {
            l = verts[i + 1]; r = verts[i];
        }
        else
            continue;

        if (point.first >= l.first && point.first < r.first) {
            //cout << l.first << " " << l.second << " " << r.first << " " << r.second << endl;
            intersectCount += ((long long) (r.second - l.second) * (point.first - l.first) >
                               (long long) (point.second - l.second) * (r.first - l.first));
        }
    }
    //cout << intersectCount << endl;
    return intersectCount % 2;
}

pair<int, int> edges[1050][2];
bool used[1050];

int main() {
//let K be # of shapes
//identify shapes (O(N^2)? but could be improved to NlogN))
//count how many shapes enclose this shape (by checking if a vertex is in the shape) (O(NK)?)
//for each cow, find the shape enclosing it with maximum enclosures itself and add to that (O(NK)?)

    int n, c, sCount = 0;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> edges[i][0].first >> edges[i][0].second >> edges[i][1].first >> edges[i][1].second;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == 0) {
            shapes[sCount].push_back(edges[i][0]);
            shapes[sCount].push_back(edges[i][1]);
            used[i] = true;

            bool done = false;
            while (!done) {
                done = false;
                for (int j = 0; j < n; j++) {
                    if (used[j])
                        continue;
                    if (edges[j][0] == shapes[sCount].back()) {
                        used[j] = true;
                        shapes[sCount].push_back(edges[j][1]);
                        if (edges[j][1] == shapes[sCount][0]) {
                            done = true;
                        }
                        break;
                    }
                    else if (edges[j][1] == shapes[sCount].back()) {
                        used[j] = true;
                        shapes[sCount].push_back(edges[j][0]);
                        if (edges[j][0] == shapes[sCount][0]) {
                            done = true;
                        }
                        break;
                    }
                }
            }
            sCount++;
        }
    }

    for (int i = 0; i < sCount; i++) {
        for (int j = 0; j < sCount; j++) {
            if (i != j) {
                encloseCount[i] += is_enclosed(shapes[j], shapes[i][0]);
            }
        }
        //cout << encloseCount[i] << endl;
    }
    //outside all shapes
    encloseCount[sCount] = -1;

    for (int i = 0; i < c; i++) {
        pair<int, int> cowPos;
        cin >> cowPos.first >> cowPos.second;

        //starts outside, if cow is not inside any shape then it will stay
        int maxIndex = sCount;
        for (int j = 0; j < sCount; j++) {
            if (is_enclosed(shapes[j], cowPos)) {
                if (encloseCount[j] > encloseCount[maxIndex]) {
                    maxIndex = j;
                }
            }
        }
        countInside[maxIndex]++;
        //cout << maxIndex << endl;
    }

    int maxCows = 0;
    for (int i = 0; i <= sCount; i++) {
        maxCows = max(maxCows, countInside[i]);
    }
    cout << maxCows << endl;

//    for (int i = 0; i < sCount; i++) {
//        for (auto a : shapes[i]) {
//            cout << a.first << " " << a.second << endl;
//        }
//        cout << endl;
//    }

    //cout << is_enclosed(shapes[0], {9, 6}) << endl;
}
/*
3 0
5 5 10 10
15 5 10 10
5 5 15 5
*/
