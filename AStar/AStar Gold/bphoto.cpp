#include <iostream>
#include <set>
using namespace std;

multiset<int> lside;
multiset<int> rside;

int n,line[100005];
//test
int main(){
    int lcount=0,rcount=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>line[i];
        rside.insert(line[i]);
    }
    for(int i=0;i<n;i++){
        lcount=distance(lside.upper_bound(line[i]),lside.end());
        rcount=distance(rside.upper_bound(line[i]),rside.end());
        /*for(multiset<int>::iterator temp=lside.upper_bound(line[i]);temp!=lside.end();temp++)
            lcount++;
        for(multiset<int>::iterator temp=rside.upper_bound(line[i]);temp!=rside.end();temp++)
            rcount++;*/
        if(lcount>2*rcount || rcount>2*lcount)
            ans++;
        rside.erase(rside.find(line[i]));
        lside.insert(line[i]);
    }
    cout<<ans<<endl;
    /*for(int i=0;i<n;i++){
        lcount=0;
        rcount=0;
        for(int j=0;j<n;j++){
            if(j<i && line[j]>line[i])
                lcount++;
            else if(j>i && line[j]>line[i])
                rcount++;
        }
        if(lcount>2*rcount || rcount>2*lcount)
            ans++;
    }
    cout<<ans<<endl;*/
}
