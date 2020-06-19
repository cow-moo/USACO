#include <iostream>
using namespace std;

int widths[100050];
int rowFirsts[100050];
int rowWidths[100050];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> widths[n - 1 - i];
    }

    int curHeight = 0;
    for (int i = 0; i < n; i++) {
        rowWidths[curHeight] += widths[i];
        if ((rowWidths[curHeight] >= rowWidths[curHeight - 1]) || curHeight == 0) {
            rowFirsts[curHeight + 1] = i + 1;
            bool change;
            do {
                change = false;
                for (int h = curHeight - 1; h >= 0; h--) {
                    while (rowWidths[h] + widths[rowFirsts[h + 1]] < rowWidths[h + 1] - widths[rowFirsts[h + 1]]
                           && rowFirsts[h + 1] < rowFirsts[h + 2] - 1){
                        change = true;
                        rowWidths[h] += widths[rowFirsts[h + 1]];
                        rowWidths[h + 1] -= widths[rowFirsts[h + 1]];
                        rowFirsts[h + 1]++;
                    }
                }
            } while (change);
            curHeight++;
        }
    }

    cout << curHeight << endl;
}

//for (int i = 0; i < curHeight; i++) {
//    cout << rowFirsts[i] << " " << rowWidths[i] << endl;;
//}
