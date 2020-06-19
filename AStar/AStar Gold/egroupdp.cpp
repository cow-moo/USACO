#include <iostream>
using namespace std;

int n,dp1[30005][4],dp2[30005][4],line[30005];

int recursedec(int index,int value){
    int minim=1000000000;
    for(int i=1;i<=value;i++){
        if(dp1[index-1][i]==-1)
            dp1[index-1][i]=recursedec(index-1,i);
        if(dp1[index-1][i]<minim)
            minim=dp1[index-1][i];
    }
    return minim+(line[index]!=value);
}

int recurseinc(int index,int value){
    int minim=1000000000;
    for(int i=value;i<=3;i++){
        if(dp2[index-1][i]==-1)
            dp2[index-1][i]=recurseinc(index-1,i);
        if(dp2[index-1][i]<minim)
            minim=dp2[index-1][i];
    }
    return minim+(line[index]!=value);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>line[i];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=3;j++){
            dp1[i][j]=-1;
            dp2[i][j]=-1;
        }
    }
    for(int i=1;i<=3;i++){
        dp1[0][i]=i!=line[0];
        dp2[0][i]=i!=line[0];
    }
    cout<<min(recursedec(n,3),recurseinc(n,1))-1<<endl;
}
