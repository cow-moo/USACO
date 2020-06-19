#include <iostream>
#include <stack>
using namespace std;

stack<int> x;
int next[100];
int h[50005],v[50005],volume[50005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i]>>v[i];
    }
    for(int i=0;i<n;i++){
        while(!x.empty() && h[i]>=h[x.top()])
            x.pop();
        if(!x.empty())
            volume[x.top()]+=v[i];
        x.push(i);
    }
    x = stack<int>();
    for(int i=n-1;i>=0;i--){
        while(!x.empty() && h[i]>=h[x.top()])
            x.pop();
        if(!x.empty())
            volume[x.top()]+=v[i];
        x.push(i);
    }
    int maximum=0;
    for(int i=0;i<n;i++){
        if(volume[i]>maximum)
            maximum=volume[i];
    }
    cout<<maximum<<endl;
}
