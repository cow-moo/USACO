#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> controllers[100050];
long long n, k;
long long totalCount, totalCost;

void countCows(long long maxCost, long long curCost, int controlIndex) {
    //if we find more cows than k, anything else doesn't matter
    if (totalCount > k)
        return;
    //if this exceeds price, any locations further on will too since it's sorted
    if (curCost + controllers[controlIndex][0] > maxCost)
        return;
    if (controlIndex + 1 < n)
        countCows(maxCost, curCost, controlIndex + 1);
    for (int i = 0; i < controllers[controlIndex].size(); i++) {
        if (curCost + controllers[controlIndex][i] <= maxCost && totalCount <= k) {
            totalCount++;
            if (controlIndex + 1 < n)
                countCows(maxCost, curCost + controllers[controlIndex][i], controlIndex + 1);
        }
        else
            return;
    }
}

void findCost(long long maxCost, long long curCost, int controlIndex) {
    if (curCost + controllers[controlIndex][0] > maxCost)
        return;
    if (controlIndex + 1 < n)
        findCost(maxCost, curCost, controlIndex + 1);
    for (int i = 0; i < controllers[controlIndex].size(); i++) {
        if (curCost + controllers[controlIndex][i] <= maxCost) {
            totalCost += curCost + controllers[controlIndex][i];
            totalCount++;
            if (controlIndex + 1 < n)
                findCost(maxCost, curCost + controllers[controlIndex][i], controlIndex + 1);
        }
        else
            return;
    }
}

int main() {
    //r1 is cost of cheapest cow
    long long r1 = 0, l = 0, r = 1000, mid;
    cin >> n >> k;

    long long inp1, inp2;
    for (int i = 0; i < n; i++) {
        cin >> inp1;
        vector<long long> v;
        for (int j = 0; j < inp1; j++) {
            cin >> inp2;
            v.push_back(inp2);
        }

        //sort components
        sort(v.begin(), v.end());
        //add smallest cost to cost of cheapest cow
        r1 += v[0];
        //if the smallest one was the only term, we can ignore that location (won't change)
        if (inp1 == 1) {
            i--;
            n--;
            continue;
        }

        //add component - cheapest for every other component
        for (int j = 1; j < inp1; j++) {
            controllers[i].push_back(v[j] - v[0]);
        }
        r += controllers[i].back();
    }

    //sort controllers
    sort(controllers, controllers + n);

    //find first cost with >= k cows
    //l <= ans <= r
    while (r > l) {
        mid = l + (r - l) / 2;

        //count cows with cost <= mid
        totalCount = 1;
        countCows(mid, 0, 0);
        if (totalCount < k) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    //find cost and count of all with less than price l
    totalCount = 1;
    totalCost = 0;
    findCost(l - 1, 0, 0);

    //we can calculate the rest using k and total count
    //this is done because there may be more cows with price l than we want
    cout << totalCost + (k - totalCount) * l + k * r1 << endl;
}
