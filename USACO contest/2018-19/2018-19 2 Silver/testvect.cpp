#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

class Foo
{

};

class Compare
{
public:
    bool operator() (pair<int,int>, pair<int,int>)
    {
        return true;
    }
};

int main(){
    std::priority_queue<pair<int,int>, std::vector<pair<int,int> >, Compare> pq;
    return 0;
}
