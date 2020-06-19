#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int> test;
multiset<int> test;

/*void ccw(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    cout<<(b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first)<<endl;
}*/

int main(){
    /*pair<int,int> first;
    pair<int,int> second;
    pair<int,int> third;
    cin>>first.first>>first.second;
    cin>>second.first>>second.second;
    cin>>third.first>>third.second;
    ccw(first,second,third);*/
    test.insert(1);
    test.insert(3);
    test.insert(5);
    test.insert(7);
    test.insert(9);
    cout<<(test.upper_bound(4)==test.upper_bound(4))<<endl;
    int counter=distance(test.upper_bound(4),test.end());
    //for(multiset<int>::iterator temp=test.upper_bound(4);temp!=test.end();temp++)
    //    counter++;
    cout<<counter<<endl;
    //cout<<test.end()<<endl;
}
