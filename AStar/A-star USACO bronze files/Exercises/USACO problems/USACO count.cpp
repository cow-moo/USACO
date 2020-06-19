#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int digits,counter=0,n,l,whichdig;
    bool temp;
    cin>>n>>l;
    for(int i=0;;i++){
        digits=counter+1;
        whichdig=0;
        temp = true;
        while(digits>0){
            if(digits%10==l){
                temp=false;
                break;
            }
            digits/=10;
            whichdig++;
        }
        if(temp)
            counter++;
        else{
            counter+=pow(10,whichdig)+1;
        }
        if(i==n-1){
            cout<<counter;
            break;
        }
        //cout<<counter<<" ";
    }
}
