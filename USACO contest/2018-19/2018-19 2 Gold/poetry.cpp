#include <iostream>
#include <stdio.h>
using namespace std;

long long mod=1000000007;

pair<long long,long long> words[5005];
long long scheme[100005];
long long rhyme[5005];
long long dp[5005];
long long storeexp[100005];

long long pow(long long base,int exp){
    //long long storeexp[100005];
    //long long storeexp[20];//base^(2^i)
    long long output=1;
    long long tempexp=base;
    while(exp>0){
        if(exp%2==1){
            output*=tempexp;
            output%=mod;
        }
        tempexp*=tempexp;
        tempexp%=mod;
        exp/=2;
    }
    /*for(int i=0;i<exp;i++){
        output*=base;
        output%=mod;
    }*/
    return output;
}

int main(){
    freopen("poetry.in","r",stdin);
    freopen("poetry.out","w",stdout);
    int n,m,k;
    long long ans=1,tempsum;
    char inp;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>words[i].first>>words[i].second;
    for(int i=0;i<m;i++){
        cin>>inp;
        scheme[inp-'A']++;
    }
    dp[0]=1;
    for(int i=1;i<k;i++){
        for(int j=0;j<n;j++){
            if(i-words[j].first>=0){
                dp[i]+=dp[i-words[j].first];
                dp[i]%=mod;
            }
        }
    }
    for(int j=0;j<n;j++){
        dp[k]+=dp[k-words[j].first];
        dp[k]%=mod;
        rhyme[words[j].second]+=dp[k-words[j].first];
        rhyme[words[j].second]%=mod;
    }
    for(int i=0;i<26;i++){
        if(scheme[i]==0)
            continue;
        tempsum=0;
        for(int j=1;j<=n;j++){
            if(rhyme[j]!=0){
                tempsum+=pow(rhyme[j],scheme[i]);
                tempsum%=mod;
            }
        }
        ans*=tempsum;
        ans%=mod;
    }
    cout<<ans<<endl;
}
