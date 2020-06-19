#include <iostream>
using namespace std;

int heights[80005][2],n; //heights[i][0] is height, heights[i][1] is how many cows they can see
long long sum;

void check(int i){
    int cowcount=0;
    while(1){
        if(heights[i][0]>heights[i+cowcount+1][0] && i+cowcount+1<n){
            cowcount+=heights[i+cowcount+1][1]+1;
        }
        else{
            break;
        }
    }
    heights[i][1]=cowcount;
    sum+=cowcount;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>heights[i][0];
    }
    for(int i=n-1;i>=0;i--){
        check(i);
    }
    cout<<sum<<endl;
}
