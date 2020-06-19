#include <iostream>
using namespace std;

int widths[100050];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> widths[n - 1 - i];
    }

    int curHeight = 0, minWidth = 0, rowWidth = 0, rowFirst = 0;
    for (int i = 0; i < n; i++) {
        rowWidth += widths[i];
        if (rowWidth >= minWidth) {
            curHeight++;
            while (minWidth + widths[rowFirst] < rowWidth - widths[rowFirst] && rowFirst < i){
                minWidth += widths[rowFirst];
                rowWidth -= widths[rowFirst];
                rowFirst++;
            }
            minWidth = rowWidth;
            rowWidth = 0;
            rowFirst = i + 1;
        }
    }

    cout << curHeight << endl;
}
