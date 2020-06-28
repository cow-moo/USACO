#include <iostream>
#include <set>
#include <queue>
using namespace std;

int dp[200050]; //dp[x] = max num of spotted cows at and after x assuming there is spotted cow at x
int pre[200050]; //pre[x] = max of b_i for all a_i <= x, gives 0 if none
int suf[200050]; //suf[x] = min of b_i for all a_i > x, gives n + 1 if none

struct MaxQueue {
    queue<int> q;
    deque<int> mq;

    void push(int val) {
        while (!mq.empty() && mq.back() < val) {
            mq.pop_back();
        }
        mq.push_back(val);
        q.push(val);
    }
    void pop() {
        if (q.front() == mq.front())
            mq.pop_front();
        q.pop();
    }
    int get_max() {
        if (mq.empty())
            return -1;
        return mq.front();
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    fill(suf, suf + n + 2, n + 1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pre[a] = max(pre[a], b);
        suf[a - 1] = min(suf[a - 1], b);
    }

    for (int i = 0; i < n; i++) {
        pre[i + 1] = max(pre[i + 1], pre[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i - 1] = min(suf[i - 1], suf[i]);
    }

    fill(dp, dp + n + 1, -1);
    dp[n + 1] = 0;
    MaxQueue q;
    for (int i = n; i >= 0; i--) {
        for (int j = max(pre[i + 1], i + 1); j > max(pre[i], i); j--)
            q.push(dp[j]);
        for (int j = max(suf[i + 1], pre[i + 1]); j > max(suf[i], pre[i]); j--)
            q.pop();
        if (q.get_max() != -1)
            dp[i] = q.get_max() + 1;
    }
    if (dp[0] == -1)
        cout << -1 << endl;
    else
        cout << dp[0] - 1 << endl;
}
