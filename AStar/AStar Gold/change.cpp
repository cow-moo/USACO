#include <iostream>
using namespace std;

int reachable[1005][2],coins[15];

int main(){
    int c,n;
    cin>>c>>n;
    for(int i=0;i<n;i++)
        cin>>coins[i];
    reachable[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            if(j+coins[i]>c)
                break;
            if(reachable[j][0]){
                if(reachable[j+coins[i]][0])
                    reachable[j+coins[i]][1]=min(reachable[j+coins[i]][1],reachable[j][1]+1);
                else
                    reachable[j+coins[i]][1]=reachable[j][1]+1;
                reachable[j+coins[i]][0]=true;
            }
        }
    }
    cout<<reachable[c][1]<<endl;
}
