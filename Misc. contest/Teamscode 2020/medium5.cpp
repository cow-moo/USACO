#include <iostream>
using namespace std;

int main() {
    int sheep, wood, brick, ore, wheat;
    cin >> sheep >> wood >> brick >> ore >> wheat;
    int pts = 0;
    if (sheep == 0 || wood == 0 || brick == 0 || wheat == 0) {
        if (sheep >= 3 && ore >= 3 && wheat >= 3) {
            cout << 2 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    else {
        sheep--; wood--; brick--; wheat--;
        int settlements = min(min(sheep, wood / 3), min(brick / 3, wheat));
        sheep -= settlements;
        wood -= 3 * settlements;
        brick -= 3 * settlements;
        wheat -= settlements;
        settlements++;
        int cities = min(settlements, min(ore / 3, wheat / 2));
        ore -= 3 * cities;
        wheat -= 2 * cities;

        if ((sheep >= 3 && wheat >= 1 && cities >= 1) || (sheep >= 2 && ore >= 3 && wheat >= 2 && cities != settlements)) {
            cout << settlements + cities + 1 << endl;
        }
        else {
            cout << settlements + cities << endl;
        }
    }
}
