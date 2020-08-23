#include <iostream>
using namespace std;

int oldFaces[10];
int newFaces[10];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 6; i++) {
        cin >> oldFaces[i];
        newFaces[i] = oldFaces[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (oldFaces[j] > oldFaces[j + 1]) {
                newFaces[j + 1] += oldFaces[j] / 2;
                newFaces[j] -= oldFaces[j] / 2;
            }
        }
        if (oldFaces[5] > oldFaces[0]) {
            newFaces[0] += oldFaces[5] / 2;
            newFaces[5] -= oldFaces[5] / 2;
        }
        for (int j = 0; j < 6; j++) {
            oldFaces[j] = newFaces[j];
        }
    }
    for (int i = 0; i < 6; i++) {
        cout << oldFaces[i] << endl;
    }
}
