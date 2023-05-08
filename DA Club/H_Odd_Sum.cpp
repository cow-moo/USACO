//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int MOD = 998244353; // 998244353
struct mint {
  int x;
  mint() : x(0) {}
  mint(ll val) : x(val % MOD) { x += (x < 0) * MOD; }
};
mint& operator+=(mint& a, mint b) { if ((a.x += b.x) >= MOD) a.x -= MOD; return a; }
mint& operator-=(mint& a, mint b) { if ((a.x -= b.x) < 0) a.x += MOD; return a; }
mint operator*(mint a, mint b) { return mint((ll) a.x * b.x); }
mint operator+(mint a, mint b) { return a += b; }
mint operator-(mint a, mint b) { return a -= b; }
mint& operator*=(mint& a, mint b) { return a = a * b; }
mint pow(mint a, ll p) { return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1); }
mint inv(mint a) { return pow(a, MOD - 2); }
mint operator/(mint a, mint b) { return a * inv(b); }

int ilog2(int n) {
  int res = 0;
  while (n >>= 1) res++;
  return res;
}

void fft(mint* a, int m, mint omega) {
  if (m == 1) return;
  fft(a, m/2,omega*omega);
  fft(a+m/2,m/2,omega*omega);
  mint cur = 1;
  for (int i=0;i<m/2;i++,cur*=omega){
    mint even = a[i], odd = a[i+m/2];
    a[i] = even + cur*odd;
    a[i+m/2] = even - cur * odd;
  }
}

void fft(vector<mint>& a, bool inv) {
  const int m = a.size();
  for (int i=1,j=0;i<m;i++){
    int bit = m >> 1;
    for (; j & bit; bit >>= 1)
      j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  mint omega = pow(mint(3), (MOD-1)/m);
  fft(a.data(),m,omega);
  if (inv) {
    reverse(a.begin()+1,a.end());
    for (mint& v : a) v = v/m;
  }
}

vector<mint> polymult(const vector<mint>& a, const vector<mint>& b) {
  int m = 1<<(ilog2(a.size()+b.size()-1)+1);
  vector<mint> a2(m), b2(m);
  for (int i=0;i<a.size();i++) a2[i] = a[i];
  for (int i=0;i<b.size();i++) b2[i] = b[i];
  fft(a2,false), fft(b2,false);
  for (int i=0;i<m;i++) a2[i] *= b2[i];
  fft(a2, true);
  return a2;
}

const int N = 1e5;

mint facts[N+1];
mint ifacts[N+1];

mint choose(int n, int k) {
  return facts[n]*ifacts[k]*ifacts[n-k];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n,m;
  cin >> n >> m;

  facts[0] = 1;
  for (int i=1;i<=n;i++){
    facts[i] = i * facts[i-1];
  }
  for (int i=0;i<=n;i++){
    ifacts[i] = inv(facts[i]);
  }

  vector<int> cnt(11);

  for (int i=0;i<n;i++){
    int a;
    cin >> a;
    cnt[a]++;
  }

  vector<vector<mint>> dp(2, vector<mint>(m+1));
  dp[0][0] = 1;
  for (int a=1;a<=10;a++){
    auto next = dp;
    int c = cnt[a];
    if (c == 0) continue;
    vector<mint> odd(c*a+1), even(c*a+1);
    for (int i=1;i<=c;i++){
      if (i % 2 == 0) {
        even[i*a] = choose(c, i);
      } else {
        odd[i*a] = choose(c, i);
      }
    }
    for (int z=0;z<2;z++) {
      auto dp_x = polymult(dp[z^1], odd);
      auto dp_y = polymult(dp[z], even);
      for (int i=0;i<=m;i++){
        next[z][i] += dp_x[i] + dp_y[i];
      }
    }
    dp = move(next);
  }
  cout << dp[1][m].x << "\n";
}
