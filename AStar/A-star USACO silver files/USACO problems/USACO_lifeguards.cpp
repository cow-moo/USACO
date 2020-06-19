#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int guards[100000][2];
/*int zero[100000];
int one[100000];
int more[100000];
int arr[1000][2];*/
//bool schedule[1000000000];
//short time[1000000000];

int partition(const int left, const int right) {
    const int mid = left + (right - left) / 2;
    const int pivot = guards[mid][0];
    swap(guards[mid][0],guards[left][0]);
    swap(guards[mid][1],guards[left][1]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && guards[i][0] <= pivot) {
            i++;
        }
        while(i <= j && guards[j][0] > pivot) {
            j--;
        }
        if (i < j) {
            swap(guards[i][0], guards[j][0]);
            swap(guards[i][1], guards[j][1]);
        }
    }
    swap(guards[i - 1][0],guards[left][0]);
    swap(guards[i - 1][1],guards[left][1]);
    return i - 1;
}
void quicksort(const int left, const int right, const int sz){
    if (left >= right) {
        return;
    }
    int part = partition(left, right);
    quicksort(left, part - 1, sz);
    quicksort(part + 1, right, sz);
}

int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    int minimum=1000000000,maximum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>guards[i][0]>>guards[i][1];
        if(guards[i][0]<minimum)
            minimum=guards[i][0];
        if(guards[i][1]>maximum)
            maximum=guards[i][1];
        //for(int j=0)
    }
    //sort(guards,guards+n);
    quicksort(0,n-1,n);
    for(int i=0;i<n;i++){
        cout<<guards[i][0]<<" "<<guards[i][1]<<endl;
    }

    /*for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(guards[i][1]<guards[j][0])
                break;
        }
    }*/

    //cout<<minimum<<" "<<maximum<<endl;
}
