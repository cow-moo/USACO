#include <iostream>
#include <queue>
#include <deque>
using namespace std;

//maxqueue stores the (not strictly) increasing subsequence (not necessarily contiguous) of all elements currently in the queue
//aka takes front element, then first element that's larger, then first element that's larger than that, etc.

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
        return mq.front();
    }
};

int main() {
    MaxQueue q;

    q.push(3);
    q.pop();
    q.pop();
    cout << q.q.size() << endl;
}
