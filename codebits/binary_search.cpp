#include <iostream>
using namespace std;

int main() {
    //given some check func that gives 11..1110..0 find last 1
    //l <= mid <= r
    int l = 0, r = ???, mid;
    while (l < r) {
        mid = r - (r - l) / 2;
        if (check(mid) == 1) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

