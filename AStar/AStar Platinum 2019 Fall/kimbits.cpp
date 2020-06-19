#include <iostream>
using namespace std;

long long nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    long long result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int main() {
    int n, l;
    long long element;
    cin >> n >> l >> element;

    string ans = "";
    for (int bit = 0; bit < n; bit++) {
        long long counter = 0;
        for (int i = 0; i <= l; i++) {
            counter += nChoosek(n - bit - 1, i);
        }
        if (counter < element) {
            ans += '1';
            l--;
            element -= counter;
        }
        else {
            ans += '0';
        }
    }

    cout << ans << endl;
}
