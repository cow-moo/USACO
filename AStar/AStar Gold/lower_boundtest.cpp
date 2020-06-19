#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

queue<int> test;
queue<int> test2;

int main(){
    test.push(1);
    test.push(14);
    test2 = test;
    cout<<test2.size()<<endl;
}
