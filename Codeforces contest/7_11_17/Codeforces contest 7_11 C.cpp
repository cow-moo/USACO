#include <iostream>
#include <string>
using namespace std;

string word[2000001];
int main(){
    for(int i=0;i<2000001;i++)
        word[i] = " ";
    int n,k,x,last=0;
    string t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t>>k;
        for(int i=0;i<k;i++){
            cin>>x;
            for(int i=0;i<t.length();i++){
                word[x-1+i]=t[i];
                if((x-1+i)>last)
                    last = x+i;
            }
        }
    }
    for(int i=0;i<last;i++)
        if(word[i]!=" ")
            cout<<word[i];
        else
            cout<<"a";
    if(word[last]!=" "){
        cout<<word[last];
    }
}
