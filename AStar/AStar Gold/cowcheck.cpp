#include <iostream>
using namespace std;

int found[1000005];

int main(){
    int m,n,s,t,x,y,j=0;
    cin>>m>>n;
    s=max(m,n);
    fill(found,found+s,-1);
    for(int i=0;i<s;i++){
        if(found[i]==-1){
            found[j]=i;
            j++;
        }
        j++;
        if(j>s)
            break;
    }
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x>>y;
        if(found[x]==y || found[y]==x){
            cout<<"Farmer John"<<endl;
        }
        else{
            cout<<"Bessie"<<endl;
        }
    }
}
