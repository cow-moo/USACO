#include <iostream>
using namespace std;

int calories[25],maxim=0,c,b;

int recurse(int curbucket,int curcal){
    if(curcal>maxim)
        maxim=curcal;
    if(curbucket>=b)
        return 0;
    if(curcal+calories[curbucket]<=c)
        recurse(curbucket+1,curcal+calories[curbucket]);
    recurse(curbucket+1,curcal);
}

int main(){
    cin>>c>>b;
    for(int i=0;i<b;i++){
        cin>>calories[i];
    }
    recurse(0,0);
    cout<<maxim<<endl;
}
