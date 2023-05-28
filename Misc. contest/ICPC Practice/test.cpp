#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int, int>> test = {{1, 1}, {2, 2}};
    int temp = lower_bound(test.begin(), test.end(), {1, 2}) - test.begin();
}