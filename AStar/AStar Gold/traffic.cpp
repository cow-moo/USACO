#include <iostream>
#include <vector>
using namespace std;

vector<int> trails[5005];
vector<int> trails2[5005];
int busy[5005],busy2[5005];

int recurse(int point){
    for(int i=1;i<=trails[point].size();i++){
        if(busy[trails[point][i-1]]>0)
            busy[point]+=busy[trails[point][i-1]];
        else
            busy[point]+=recurse(trails[point][i-1]);
    }
    return busy[point];
}

int recurse2(int point){
    for(int i=1;i<=trails2[point].size();i++){
        if(busy2[trails2[point][i-1]]>0)
            busy2[point]+=busy2[trails2[point][i-1]];
        else
            busy2[point]+=recurse2(trails2[point][i-1]);
    }
    return busy2[point];
}

int main(){
    int n,m,input1,input2,maxim=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>input1>>input2;
        trails[input2].push_back(input1);
        trails2[input1].push_back(input2);
    }
    for(int i=1;i<=n;i++){
        if(trails[i].size()==0)
            busy[i]=1;
        if(trails2[i].size()==0)
            busy2[i]=1;
    }
    recurse(n);
    recurse2(1);
    for(int i=1;i<n;i++){
        for(int j=0;j<trails2[i].size();j++){
            if(busy[i]*busy2[trails2[i][j]]>maxim)
                maxim=busy[i]*busy2[trails2[i][j]];
        }
    }
    cout<<maxim<<endl;
}
