#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int cows[100005];
vector<int> newline;

int main(){
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>cows[i];
    for(int i=n-1;i>=1;i--){
        if(cows[i]>cows[i+1]){
            k=i;
            break;
        }
    }
    for(int i=k+1;i<=n;i++)
        newline.push_back(cows[i]);
    cout<<k<<endl;
    for(int i=1;i<k;i++){
        cout<<lower_bound(newline.begin(),newline.end(),cows[i])-newline.begin()-i+k<<" ";
        /*for(vector<int>::iterator it=newline.begin();it!=newline.end();++it)
            cout<<*it<<" ";
        cout<<endl;*/
        newline.insert(lower_bound(newline.begin(),newline.end(),cows[i]),cows[i]);
    }
    cout<<lower_bound(newline.begin(),newline.end(),cows[k])-newline.begin();
    newline.insert(lower_bound(newline.begin(),newline.end(),cows[k]),cows[k]);
    cout<<endl;
    //for(vector<int>::iterator it=newline.begin();it!=newline.end();++it)
    //    cout<<*it<<endl;
}
