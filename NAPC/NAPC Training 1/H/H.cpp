#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MOD = (int)1e9 + 7;

ll binexp(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n&1) res = res*x % MOD;
        x = x*x % MOD;
        n /= 2;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r,c;
        cin >> r >> c;
        cout << binexp(3,r+c)*binexp(2,(ll)r*c) % MOD << "\n";
    }
}