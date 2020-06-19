#include <iostream>
#include <algorithm>
using namespace std;

int pos[1005],n,l,minim=100000000;
bool temporary[1005];

void recurse(int curi,int curt,bool eaten[],int stale){
    if(stale>=minim)
        return;
    //cout<<curt<<" t"<<endl;
    bool eatenall=true;
    for(int i=0;curi+i>=0;i--){
        if(!eaten[curi+i]){
            eatenall=false;
            eaten[curi+i]=1;
            //cout<<curi+i<<endl;
            //cout<<pos[curi]-pos[curi+i]<<" pos"<<endl;
            recurse(curi+i,curt+(pos[curi]-pos[curi+i]),eaten,stale+curt+(pos[curi]-pos[curi+i]));
            eaten[curi+i]=0;
            break;
        }
    }
    for(int i=0;curi+i<n;i++){
        if(!eaten[curi+i]){
            eatenall=false;
            eaten[curi+i]=1;
            //cout<<curi+i<<endl;
            //cout<<pos[curi+i]-pos[curi]<<" pos"<<endl;
            recurse(curi+i,curt+(pos[curi+i]-pos[curi]),eaten,stale+curt+(pos[curi+i]-pos[curi]));
            eaten[curi+i]=0;
            break;
        }
    }
    /*for(int i=0;i<n;i++)
        cout<<eaten[i]<<" ";
    cout<<endl;*/

    if(eatenall && stale<minim)
        minim = stale;
}

int main(){
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>pos[i];
    }
    sort(pos,pos+n);
    for(int i=0;i<n;i++){
        if(l<=pos[i]){
            i--;
            temporary[i]=1;
            recurse(i,l-pos[i],temporary,l-pos[i]);
            temporary[i]=0;
            temporary[i+1]=1;
            recurse(i+1,pos[i+1]-l,temporary,pos[i+1]-l);
            break;
        }
    }
    cout<<minim<<endl;
}
