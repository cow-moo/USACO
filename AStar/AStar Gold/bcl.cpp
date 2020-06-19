#include <iostream>
using namespace std;

char cows[2005];

int main(){
    int n,lindex=0,rindex;
    string ans;
    cin>>n;
    rindex=n-1;
    for(int i=0;i<n;i++)
        cin>>cows[i];
    for(int i=0;i<n;i++){
        if(cows[lindex]==cows[rindex] && rindex>=lindex+3){
            for(int j=1;;j++){
                if(cows[lindex+j]<cows[rindex-j]){
                    ans+=cows[lindex++];
                    break;
                }
                else if(cows[lindex+j]>cows[rindex-j] || lindex>=rindex){
                    ans+=cows[rindex--];
                    break;
                }
            }
        }
        else if(cows[lindex]<cows[rindex])
            ans+=cows[lindex++];
        else
            ans+=cows[rindex--];
    }
    for(int i=0;i<ans.size()/80;i++)
        cout<<ans.substr(i*80,80)<<endl;
    cout<<ans.substr(ans.size()/80*80,-1)<<endl;
}
