#include <iostream>
using namespace std;

int pfx[10000];//1 indexed
int maxn;//highest value needed

void update(int x,int v){
    while(x<=maxn){
        pfx[x]+=v;
        x+=(x&(-x));
    }
}

int query(int x){
    int ans=0;
    while(x>0){
        ans+=pfx[x];
        x-=(x&(-x));
    }
    return ans;
}

int main(){
}
