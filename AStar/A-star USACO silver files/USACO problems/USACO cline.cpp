#include <iostream>
using namespace std;

int line[200005],curcow=1,lengthl=100000,lengthr=100000;

int main(){
    char input;
    int s,inp;
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>input;
        if(input=='A'){
            cin>>input;
            if(input=='L')
                line[--lengthl]=curcow++;
            else
                line[lengthr++]=curcow++;
        }
        if(input=='D'){
            cin>>input;
            if(input=='L'){
                cin>>inp;
                lengthl+=inp;
            }
            else{
                cin>>inp;
                lengthr-=inp;
            }
        }
    }
    for(int i=lengthl;i<lengthr;i++){
        cout<<line[i]<<endl;
    }
}
