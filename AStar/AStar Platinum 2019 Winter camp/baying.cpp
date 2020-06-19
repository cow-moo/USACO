#include <iostream>
#include <queue>
using namespace std;

long long a1, b1, d1, a2, b2, d2;

long long f1(long long x) {
    return a1 * x / d1 + b1;
}

long long f2(long long x) {
    return a2 * x / d2 + b2;
}

queue<long long> f1Output;
queue<long long> f2Output;

int main() {
    long long c, n, counter = 0, next;
    cin >> c >> n >> a1 >> b1 >> d1 >> a2 >> b2 >> d2;

    f1Output.push(f1(c));
    f2Output.push(f2(c));

    for (int i = 0; i < n - 1; i++) {
        if (f1Output.front() < f2Output.front()) {
            next = f1Output.front();
            f1Output.pop();
            if (f1(next) > f1Output.back() && f1Output.size() < (n - i + 100)) {
                f1Output.push(f1(next));
            }
            if (f2(next) > f2Output.back() && f2Output.size() < (n - i + 100)) {
                f2Output.push(f2(next));
            }
        }
        else {
            next = f2Output.front();
            f2Output.pop();
            if (f1(next) > f1Output.back() && f1Output.size() < (n - i + 100)) {
                f1Output.push(f1(next));
            }
            if (f2(next) > f2Output.back() && f2Output.size() < (n - i + 100)) {
                f2Output.push(f2(next));
            }

            if (f1Output.front() == next) {
                f1Output.pop();
            }
        }
    }
    cout << next << endl;
}
