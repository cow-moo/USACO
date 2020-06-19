#include <iostream>
#include <vector>
using namespace std;

int cows[105];
vector<int> pastures[1005];
bool visited[1005][105];

int dfs(int curcow,int curpast){
    for(int i=0;i<pastures[curpast].size();i++){
        if(!visited[pastures[curpast][i]][curcow]){
            visited[pastures[curpast][i]][curcow]=true;
            dfs(curcow,pastures[curpast][i]);
        }
    }
}

int main(){
    int k,n,m,input1,input2,ans=0;
    cin>>k>>n>>m;
    for(int i=0;i<k;i++)
        cin>>cows[i];
    for(int i=0;i<m;i++){
        cin>>input1>>input2;
        pastures[input1].push_back(input2);
    }
    for(int i=0;i<k;i++){
        visited[cows[i]][i]=true;
        dfs(i,cows[i]);
    }
    bool allvisit;
    for(int i=1;i<=n;i++){
        allvisit=true;
        for(int j=0;j<k;j++){
            if(!visited[i][j])
                allvisit=false;
        }
        if(allvisit)
            ans++;
    }
    cout<<ans<<endl;
}
