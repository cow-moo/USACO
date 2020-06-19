#include <iostream>
#include <algorithm>
using namespace std;

string start,ending,dict[25005];
bool visited[25005];
int que[25005],questart=0,queend=0,n,length,dist[25005],ans[15],anscount;

bool checkadj(string str,string x){
    bool diff=false;
    for(int j=0;j<str.length();j++){
        if(str[j]!=x[j]){
            if(diff){
                diff=false;
                break;
            }
            else
                diff=true;
        }
    }
    return diff;
}

void bfs(){
    string curstr=start;
    while(1){
        for(int i=0;i<n;i++){
            if(visited[i])
                continue;
            if(checkadj(curstr,dict[i])){
                dist[i]=dist[que[questart-1]]+1;
                visited[i]=true;
                que[queend++]=i;
            }
        }
        curstr=dict[que[questart++]];
        if(curstr==ending){
            return;
        }
    }
}

int main(){
    cin>>start>>ending;
    string temp;
    while(1){
        cin>>temp;
        if(temp.length()==start.length())
            dict[n++]=temp;
        if(temp=="conceal")
            break;
    }
    dict[n++]=ending;
    bfs();
    cout<<dist[n-1]<<endl;
}
