#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int rc1[20000][2],rc2[20000][2],cowpos[105][2],n,k,r,dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

queue<int> quer;
queue<int> quec;
vector<int> visitedr;
vector<int> visitedc;

int bfs(int cow){
    int ncount=0;
    bool road[4];
    quer.push(cowpos[cow][0]);
    quec.push(cowpos[cow][1]);
    visitedr.push_back(quer.front());
    visitedc.push_back(quec.front());
    //cout<<"starts at "<<quer.front()<<" "<<quec.front()<<endl;
    while(quer.size()>0){
        for(int i=0;i<4;i++){
            road[i]=0;
        }
        for(int i=0;i<r;i++){
            if(rc1[i][0]==quer.front() && rc1[i][1]==quec.front()){
                for(int j=0;j<4;j++){
                    if(dir[j][0]==(rc2[i][0]-rc1[i][0]) && dir[j][1]==(rc2[i][1]-rc1[i][1])){
                        road[j]=1;
                        break;
                    }
                }
            }
            if(rc2[i][0]==quer.front() && rc2[i][1]==quec.front()){
                for(int j=0;j<4;j++){
                    if(dir[j][0]==(rc1[i][0]-rc2[i][0]) && dir[j][1]==(rc1[i][1]-rc2[i][1])){
                        road[j]=1;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<visitedr.size();i++){
            for(int j=0;j<4;j++){
                if(dir[j][0]==(visitedr[i]-quer.front()) && dir[j][1]==(visitedc[i]-quec.front())){
                    road[j]=1;
                    //cout<<"quer:"<<quer.front()<<" quec:"<<quec.front()<<" visitedr:"<<visitedr[i]<<" visitedc:"<<visitedc[i]<<endl;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            if(!road[i] && (quer.front()+dir[i][0])>=1 && (quer.front()+dir[i][0])<=n && (quec.front()+dir[i][1])>=1 && (quec.front()+dir[i][1])<=n){
                quer.push(quer.front()+dir[i][0]);
                quec.push(quec.front()+dir[i][1]);
                visitedr.push_back(quer.back());
                visitedc.push_back(quec.back());
                //cout<<quer.front()<<" "<<quec.front()<<" to "<<quer.back()<<" "<<quec.back()<<endl;
                for(int j=0;j<k;j++){
                    if(cowpos[j][0]==quer.back() && cowpos[j][1]==quec.back()){
                        //cout<<cow<<" can go to "<<j<<endl;
                        ncount++;
                    }
                }
            }
        }
        quer.pop();
        quec.pop();
    }
    /*for(int i=0;i<visitedr.size();i++){
        cout<<"visited "<<visitedr[i]<<" "<<visitedc[i]<<endl;
    }*/
    //cout<<cow<<" "<<ncount<<endl;
    return ncount;
}

int main(){
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);
    int ans=0;
    cin>>n>>k>>r;
    for(int i=0;i<r;i++){
        cin>>rc1[i][0]>>rc1[i][1]>>rc2[i][0]>>rc2[i][1];
    }
    for(int i=0;i<k;i++){
        cin>>cowpos[i][0]>>cowpos[i][1];
    }
    for(int i=0;i<k;i++){
        ans+=k-(bfs(i)+1);
        visitedc.clear();
        visitedr.clear();
    }
    cout<<ans/2<<endl;
    //bfs(2);
}
