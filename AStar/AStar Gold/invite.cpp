#include <iostream>
#include <set>
#include <queue>
using namespace std;

int n,g;
set<int> groups[250000];
queue<int> que;
bool alreadyinv[1000000];

int main(){
    int input,invnum=0,temps;
    cin>>n>>g;
    for(int i=0;i<g;i++){
        cin>>temps;
        for(int j=0;j<temps;j++){
            cin>>input;
            groups[i].insert(input);
        }
    }
    set<int>::iterator temp;
    que.push(1);
    while(!que.empty()){
        for(int i=0;i<g;i++){
            temp=groups[i].find(que.front());
            if(temp!=groups[i].end()){
                groups[i].erase(temp);
                if(groups[i].size()==1 && !alreadyinv[*groups[i].begin()]){
                    que.push(*groups[i].begin());
                    alreadyinv[que.back()]=1;
                }
            }
        }
        invnum++;
        que.pop();
    }
    cout<<invnum<<endl;
}
