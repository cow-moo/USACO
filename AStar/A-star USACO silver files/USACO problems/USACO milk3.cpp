#include <iostream>
#include <algorithm>
using namespace std;

int capacity[5];
int buckets[5];
int buckethist[8050][3];
int histcount=0;
int ans[8050],anscount=0;

void printbuckets(){
    for(int i=0;i<3;i++){
        cout<<buckets[i]<<"/"<<capacity[i]<<" ";
    }
    cout<<endl;
}

void pour(int first, int last){
    if(capacity[last]-buckets[last]<=buckets[first]){
        buckets[first]-=capacity[last]-buckets[last];
        buckets[last]=capacity[last];
    }
    else{
        buckets[last]+=buckets[first];
        buckets[first]=0;
    }
}

void recurse(){
    int a=buckets[0],b=buckets[1],c=buckets[2];
    for(int i=0;i<histcount;i++){
        if(buckethist[i][0]==buckets[0] && buckethist[i][1]==buckets[1] && buckethist[i][2]==buckets[2]){
            return;
        }
    }
    buckethist[histcount][0]=buckets[0];
    buckethist[histcount][1]=buckets[1];
    buckethist[histcount][2]=buckets[2];
    histcount++;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i!=j && buckets[i]!=0){
                pour(i,j);
                recurse();
                buckets[0]=a; buckets[1]=b; buckets[2]=c;
            }
        }
    }
}

int main(){
    cin>>capacity[0]>>capacity[1]>>capacity[2];
    buckets[2]=capacity[2];
    recurse();
    for(int i=0;i<histcount;i++){
        if(buckethist[i][0]==0){
            ans[anscount]=buckethist[i][2];
            anscount++;
        }
    }
    sort(ans,ans+anscount);
    for(int i=0;i<anscount;i++){
        cout<<ans[i]<<" ";
    }
}
