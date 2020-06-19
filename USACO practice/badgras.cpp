#include <iostream>
using namespace std;

bool grass[1005][1005];
short islands[1005][1005];
int r,c,ans=1;

void findisland(int i,int j,int islnum){
    for(int a=-1;a<=1;a++){
        for(int b=-1;b<=1;b++){
            if(!(a==0 && b==0) && i+a>=0 && i+a<r && j+b>=0 && j+b<r && grass[i+a][j+b]==1 && islands[i+a][j+b]==0){
                islands[i+a][j+b]=islnum;
                findisland(i+a,j+b,islnum);
            }
        }
    }
}

int main(){
    int temp;
    bool found;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>temp;
            if(temp>0)
                grass[i][j]=1;
            else
                grass[i][j]=0;
        }
    }
    /*for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<grass[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grass[i][j]==1 && islands[i][j]==0){
                findisland(i,j,ans++);
                /*found=false;
                for(int a=-1;a<=1;a++){
                    for(int b=-1;b<=1;b++){
                        if(!(a==0 && b==0) && i+a>=0 && i+a<r && j+b>=0 && j+b<r){
                            if(islands[i+a][j+b]>0 && grass[i+a][j+b]==1){
                                islands[i][j]=islands[i+a][j+b];
                                found=true;
                            }
                        }
                    }
                }
                if(!found){
                    cout<<i<<" "<<j<<endl;
                    findisland(i,j,ans);
                    //islands[i][j]=ans++;
                }*/
            }
        }
    }
    /*for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<islands[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<ans-1<<endl;
    for(int i=0;i<100000000000000;i++){
        cin.get();
    }
}
