#include <iostream>
using namespace std;

int sums[81];
int main(){
    int s1,s2,s3,maxsum=0;
    cin>>s1>>s2>>s3;
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            for(int k=1;k<=s3;k++){
                sums[i+j+k]++;
            }
        }
    }
    for(int i=3;i<=s1+s2+s3;i++){ //i is the sum, the value is the frequency
        if(sums[i]>sums[maxsum]){
            maxsum=i;
        }
    }
    cout<<maxsum;
}
