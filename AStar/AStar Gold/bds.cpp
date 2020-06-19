#include <iostream>
using namespace std;

int binomial[15],n,sum;
bool complete = false;

int factorial(int n){
    int temp=1;
    for(int i=2;i<=n;i++){
        temp*=i;
    }
    return temp;
}

int choose(int n,int k){
    return factorial(n)/(factorial(k)*factorial(n-k));
}

void recurse(int order[15],int index){
    if(complete)
        return;
    if(index==n){
        int tempsum=0;
        for(int i=0;i<n;i++){
            tempsum+=binomial[i]*order[i];
        }
        if(sum==tempsum){
            complete=true;
            for(int i=0;i<n;i++){
                cout<<order[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++){
        bool alreadyused = false;
        for(int j=0;j<index;j++){
            if(i==order[j]){
                alreadyused = true;
                break;
            }
        }
        if(!alreadyused){
            order[index]=i;
            recurse(order,index+1);
            order[index]=0;
        }
    }
}

int temp[15];

int main(){
    cin>>n>>sum;
    for(int i=0;i<n;i++){
        binomial[i] = choose(n-1,i);
    }
    recurse(temp,0);
}
