#include <iostream>
#include <deque>
using namespace std;

deque<int> line;

void enter(int cownum,char side){
    if(side=='R'){
        line.push_back(cownum);
    }
    else{
        line.push_front(cownum);
    }
}

void exit(int k,char side){
    if(side=='R'){
        for(int i=0;i<k;i++)
            line.pop_back();
    }
    else{
        for(int i=0;i<k;i++)
            line.pop_front();
    }
}

int main(){
    int s,curcow=1;
    char tempa,temps;
    int tempk;
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>tempa>>temps;
        if(tempa=='A'){
           enter(curcow++,temps);
        }
        else{
            cin>>tempk;
            exit(tempk,temps);
        }
    }
    for(int i=0;i<line.size();i++){
        cout<<line[i]<<endl;
    }
}
