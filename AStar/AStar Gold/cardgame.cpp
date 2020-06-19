#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int elsie[50005];
vector<int> bessie;
bool used[100005];

int main(){
    int n,pts=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>elsie[i];
        used[elsie[i]]=true;
    }
    sort(elsie,elsie+n/2);
    sort(elsie+n/2,elsie+n);
    for(int i=1;i<=2*n;i++){
        if(!used[i])
            bessie.push_back(i);
    }
    for(int i=n/2-1;i>=0;i--){
        if(bessie[bessie.size()-1]>elsie[i]){
            pts++;
            bessie.erase(bessie.end()-1);
        }
    }
    for(int i=n/2;i<n;i++){
        if(bessie[0]<elsie[i]){
            pts++;
            bessie.erase(bessie.begin());
        }
    }
    cout<<pts<<endl;
}
