#include <iostream>
#include <stdio.h>
using namespace std;

int arr[105];
int negi[105];
int main(){
    int n,totalsum=0,sum=0,mini,maxi,counter=0,maxvalue=-100;
    cin>>n;
    mini=0;
    maxi=n-1;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        totalsum+=arr[i];
        if(arr[i]<0){
            negi[counter]=i;
            counter++;
        }
    }
    if(counter==n){
        for(int i=0;i<n;i++){
            if(arr[i]>maxvalue)
                maxvalue=arr[i];
        }
        cout<<maxvalue;
    }
    else{
        for(int i=0;i<counter;i++){
            sum=0;
            if(negi[i]<(n/2) || (n%2==1 && negi[i]==(n/2))){
                for(int j=mini;j<=negi[i];j++){
                    sum+=arr[j];
                }
                if(sum<0){
                    totalsum-=sum;
                    mini=negi[i]+1;
                }
            }
            if(negi[i]>=(n/2)){
                break;
            }
        }
        for(int i=counter-1;i>=0;i--){
        sum=0;
            if(negi[i]<(n/2) || (n%2==1 && negi[i]==(n/2))){
                break;
            }
            if(negi[i]>=(n/2)){
                for(int j=maxi;j>=negi[i];j--){
                    sum+=arr[j];
                }
                if(sum<0){
                    totalsum-=sum;
                    maxi=negi[i]-1;
                }
            }
        }
        cout<<totalsum;
    }
}
