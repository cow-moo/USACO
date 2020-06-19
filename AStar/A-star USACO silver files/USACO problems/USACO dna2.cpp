#include <iostream>
#include <algorithm>
using namespace std;

string dna[10];
int n,minlength=100;

string mergedna(string dna1,string dna2){
    for(int i=min(dna1.length(),dna2.length());i>=0;i--){
        if(dna1.substr(dna1.length()-i,i)==dna2.substr(0,i)){
            return dna1.substr(0,dna1.length()-i)+dna1.substr(dna1.length()-i,i)+dna2.substr(i,dna2.length()-i);
        }
    }
}

string mergeall(){
    string temp = dna[0];
    for(int i=1;i<n;i++){
        temp = mergedna(temp,dna[i]);
    }
    return temp;
}

void recurse(int curr){
    if(curr==n-1){
        if(mergeall().length()<minlength){
            minlength=mergeall().length();
        }
        return;
    }
    for(int i=curr;i<n;i++){
        swap(dna[i],dna[curr]);
        recurse(curr+1);
        swap(dna[i],dna[curr]);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dna[i];
    }
    recurse(0);
    cout<<minlength<<endl;
}
