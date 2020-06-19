#include <iostream>
#include <algorithm>
using namespace std;

int arr[505],n;
int side=2;

int quicksort(int first, int last){
    int left = first, right = last-1;
    while(left<=right){
        while(arr[left]<=arr[last] && left<last)
            left++;
        while(arr[right]>arr[last])
            right--;
        if(left>=right)
            break;
        /*if(left>=last-1 || right<=first-1)
            return 0;*/
        swap(arr[left],arr[right]);
        /*if(side == 1 || first==2 && last==4){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"l:"<<left<<" r:"<<right;
        cout<<endl;}*/
        //cout<<"swapped"<<endl;
    }
    cout<<left<<" "<<last<<" swapped"<<endl;
    swap(arr[left],arr[last]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    //cout<<"left-first: "<<left-first;
    cout<<endl;
    //cout<<left<<" "<<side<<endl;
    if(left-first>1){
        side = 0;
        cout<<"first:"<<first<<" last:"<<left-1<<" side:"<<side<<endl;
        quicksort(first,left-1);
    }
    if(last-left>1){
        side = 1;
        cout<<"first:"<<left+1<<" last:"<<last<<" side:"<<side<<endl;
        quicksort(left+1,last);
    }

}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(0,n-1);
    /*quicksort(0,3);
    quicksort(5,n-1);*/
}
