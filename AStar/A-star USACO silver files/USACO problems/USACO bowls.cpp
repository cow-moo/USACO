#include <iostream>
using namespace std;

bool bowls[25],bowls2[25];
int minflips=1000000;

void flip(int pos){
    if(pos<0 || pos>=20)
        return;
    for(int i=-1;i<=1;i++){
        if(pos+i<0 || pos+i>=20)
            continue;
        bowls[pos+i]=1-bowls[pos+i];
    }
}

void recurse(int flips){
    bool done = true;
    for(int i=0;i<20;i++){
        if(bowls[i]==1){
            done = false;
            flip(i+1);
            recurse(flips+1);
        }
    }
    if(done){
        if(flips<minflips)
            minflips=flips;
    }
}

int main(){
    for(int i=0;i<20;i++){
        cin>>bowls[i];
        bowls2[i]=bowls[i];
    }
    recurse(0);
    for(int i=0;i<20;i++){
        bowls[i]=bowls2[i];
    }
    flip(0);
    recurse(1);
    cout<<minflips<<endl;
}
