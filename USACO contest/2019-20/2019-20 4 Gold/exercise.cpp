#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define MAXN 10005

bool isPrime[MAXN];
vector<int> primes;
vector<int> exponents;
long long powers[1235][15]; //[base][exponent]

int main() {
    freopen("exercise.in", "r", stdin);
    //freopen("exercise.out", "w", stdout);

    int n;
    long long m;
    cin >> n >> m;

    for (int i = 2; i <= n; i++)
        isPrime[i] = true;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            exponents.push_back(0);
        }
    }
    //cout << primes.size() << endl;

    for (int i = 0; i < primes.size(); i++) {
        int product = 1;
        for (int e = 1; ; e++) {
            product = (product * primes[i]) % m;
            powers[i][e] = product;
            if (product > n)
                break;
        }
    }
    //cout << 'f';
//    for (int i = 0; i < primes.size(); i++) {
//        for (int e = 0; e < 10; e++) {
//            cout << powers[i][e] << " ";
//        }
//        cout << endl;
//    }

    long long sum = 0; //sum of cycle lengths excluding length 1s
    long long ans = 1;
    long long product = 1;
    bool done = false;
    while (!done) {
        for (int i = 0; i <= primes.size(); i++) {
            if (i == primes.size()) {
                done = true;
                break;
            }
            sum += powers[i][exponents[i] + 1] - powers[i][exponents[i]];
            exponents[i]++;
            if (sum <= n)
                break;
            else {
                sum -= powers[i][exponents[i]];
                exponents[i] = 0;
            }
        }
        if (done)
            break;
        //cout << sum << endl;
        product = 1;
        for (int i = 0; i < exponents.size(); i++) {
            if (exponents[i] != 0)
                product = (product * powers[i][exponents[i]]) % m;
            //cout << exponents[i] << " ";
        }
        //cout << endl;
        ans = (ans + product) % m;
        //cout << product << endl;
    }
    cout << ans << endl;
}
