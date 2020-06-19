#include <iostream>
using namespace std;

int n,finalc,finalon[105],finaloff[105],finaloncount,finaloffcount,anscount=0;
bool lamps[105];
string ans[105];

void resetlamps(){
    for(int i=0;i<n;i++)
        lamps[i]=1;
}

void check(){
    for(int i=0;i<finaloncount;i++){
        if(lamps[finalon[i]]==0)
            return;
    }
    for(int i=0;i<finaloffcount;i++){
        if(lamps[finaloff[i]]==1)
            return;
    }
    bool same=true;
    for(int i=0;i<anscount;i++){
        same=true;
        for(int j=0;j<n;j++){
            if((ans[j][i]-'0')!=lamps[j]){
                same=false;
                break;
            }
        }
        if(same)
            return;
    }
    for(int i=0;i<n;i++){
        ans[anscount]+=lamps[i]+'0';
    }
    anscount++;
}

void button(int x){
    if(x==0){
        for(int i=0;i<n;i++)
            lamps[i]=1-lamps[i];
    }
    else if(x==1){
        for(int i=0;i<n;i+=2)
            lamps[i]=1-lamps[i];
    }
    else if(x==2){
        for(int i=1;i<n;i+=2)
            lamps[i]=1-lamps[i];
    }
    else{
        for(int i=0;i<n;i+=3)
            lamps[i]=1-lamps[i];
    }
}

void recurse(){
    resetlamps();
    check();
    if((finalc%2==0 && finalc>=4) || (finalc%2==1 && finalc>=1)){
        for(int i=0;i<4;i++){
            button(i);
            check();
            resetlamps();
        }
    }
    if((finalc&2==0 && finalc>=2) || (finalc%2==1 && finalc>=5)){
        for(int i=0;i<4;i++){
            for(int j=i+1;j<4;j++){
                button(i);
                button(j);
                check();
                resetlamps();
            }
        }
    }
    if((finalc%2==0 && finalc>=6) || (finalc%2==1 && finalc>=3)){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(j!=i)
                    button(j);
            }
            check();
            resetlamps();
        }
    }
    if((finalc%2==0 && finalc>=4) || (finalc%2==1 && finalc>=7)){
        for(int i=0;i<4;i++)
            button(i);
        check();
        resetlamps();
    }
}

int main(){
    cin>>n>>finalc;
    int temp;
    while(1){
        cin>>temp;
        temp--;
        if(temp>=0)
            finalon[finaloncount++]=temp;
        else
            break;
    }
    while(1){
        cin>>temp;
        temp--;
        if(temp>=0)
            finaloff[finaloffcount++]=temp;
        else
            break;
    }
    recurse();
    for(int i=0;i<anscount;i++){
        cout<<ans[i]<<endl;
    }
    if(anscount==0)
        cout<<"IMPOSSIBLE"<<endl;
}
