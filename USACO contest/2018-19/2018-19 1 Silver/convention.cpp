#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;

int times[100005];
//int dividers[100005];
set<int> dividers;

int main(){
    //freopen("convention.in","r",stdin);
    //freopen("convention.out","w",stdout);
    int n,m,c,minim=1000000000,minindex;
    cin>>n>>m>>c;
    for(int i=0;i<n;i++){
        cin>>times[i];
    }
    sort(times,times+n);
    for(int i=0;i<m-1;i++){
        dividers.insert(i);
    }
    //i starts at 3
    /*for(int i=m;i<n;i++){ //adding element i
        for(int j=0;j<m-1;j++){
            if(times[dividers[j+1]]-times[dividers[j]]<minim){
                minim=times[dividers[j+1]]-times[dividers[j]];
                minindex=j;
            }
            //else if(times[dividers[j+1]]-times[dividers[j]]==minim && ){

            //}
        }
        if(times[i]-times[i-1]<minim){

        }
        else{
           dividers[minindex]=i-1;
        }
        minim=1000000000;
    }*/
    for(int i=m;i<n;i++){
        for
    }
}
