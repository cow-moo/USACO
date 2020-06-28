#include <iostream>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

#define ll long long

struct Line {
	mutable ll k, m, p;
	//bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<ll> > {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = 100000000000000;//LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
	    if (empty())
            return x;
		//assert(!empty());
		auto l = *this->lower_bound(x);
		return l.k * x + l.m;
	}
};

//width, height
pair<int, int> plots[50005]; //plots[j].second is m

//dp[i] = min(dp[j] + width[i - 1] * height[j])
int dp[50005]; //dp[j] is b

LineContainer hull;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> plots[i].first >> plots[i].second;
    }

    sort(plots, plots + n);

    int rn = 0; //reduced n, we get rid of all plots that are completely enclosed
    for (int i = 0; i < n; i++) {
        while (rn - 1 >= 0 && plots[i].second >= plots[rn - 1].second) {
            rn--;
        }
        plots[rn++] = plots[i];
    }

    hull.add(plots[0].second, 0);
    for (int i = 1; i <= n; i++) {
        dp[i] = hull.query(plots[i - 1].first);

        hull.add(plots[i].second, dp[i]);
    }

    cout << dp[n] << endl;

//    int hullsz = 0;
//    for (int i = 1; i <= n; i++) {
//        int j = (lower_bound(hull, hull + hullsz, plots[i - 1].first, comp) - 1)->second;
//        dp[i] = dp[j] + plots[i - 1].first * plots[j].second;
//        break;
//    }
//
//    cout << dp[0] << " " << dp[1] << endl;

//    cout << endl;
//    for (int i = 0; i < rn; i++)
//        cout << plots[i].first << " " << plots[i].second << endl;
}
/*
6
100 1
15 15
20 5
1 100
7 7
20 6
*/

