#include <iostream>
using namespace std;

int n,groups[30005],minim=1000000000;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>groups[i];
    }
    int counter=0,temp=0;
    for(int i=-1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(groups[j]!=1)
                temp++;
        }
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){
                if(groups[k]!=2)
                    counter++;
            }
            for(int k=j;k<n;k++){
                if(groups[k]!=3)
                    counter++;
            }
            if(counter<minim)
                minim=counter;
            counter=temp;
        }
        temp=0;
    }
    for(int i=-1;i<n;i++){
        for(int j=0;j<=i;j++){//0 to i
            if(groups[j]!=3)
                temp++;
        }
        for(int j=i+1;j<=n;j++){
            for(int k=i+1;k<j;k++){//i+1 to j-1
                if(groups[k]!=2)
                    counter++;
            }
            for(int k=j;k<n;k++){//j to n-1
                if(groups[k]!=1)
                    counter++;
            }
            if(counter<minim){
                minim=counter;
            }
            counter=temp;
        }
        temp=0;
    }
    cout<<minim<<endl;
}
