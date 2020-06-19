#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cows[1005][2];
vector<pair<int,int> > midpoint;

int main(){
    int n,counter=0,tempsize,curcount=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>cows[i][0]>>cows[i][1];
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            midpoint.push_back(make_pair(cows[i][0]+cows[j][0],cows[i][1]+cows[j][1]));
    }
    sort(midpoint.begin(),midpoint.end());
    for(int i=1;i<midpoint.size();i++){
        if(midpoint[i]==midpoint[i-1])
            curcount++;
        else
            curcount=0;
        counter+=curcount;
    }
    cout<<counter<<endl;
}
