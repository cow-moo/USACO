#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n;
pair<int,int> line[50005];
map<int,int> breeds1;
map<int,int> breeds2;

int main(){
    int l1,r1,l2,r2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>line[i].first>>line[i].second;
        breeds1[line[i].second]++;
    }
    breeds2=breeds1;
    sort(line,line+n);
    for(int i=n-1;i>=0;i--){
        if(breeds1[line[i].second]>1)
            breeds1[line[i].second]--;
        else{
            r1=line[i].first;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(breeds1[line[i].second]>1)
            breeds1[line[i].second]--;
        else{
            l1=line[i].first;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(breeds2[line[i].second]>1)
            breeds2[line[i].second]--;
        else{
            l2=line[i].first;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(breeds2[line[i].second]>1)
            breeds2[line[i].second]--;
        else{
            r2=line[i].first;
            break;
        }
    }
    if((r2-l2)>(r1-l1))
        cout<<r1-l1<<endl;
    else
        cout<<r2-l2<<endl;
}
