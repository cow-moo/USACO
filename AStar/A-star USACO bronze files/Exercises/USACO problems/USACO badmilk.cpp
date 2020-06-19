#include <iostream>
using namespace std;

int p[1010],m[1010],t[1010],sickp[1010],sickt[1010];
int main(){
    int n,milks,d,s,maxsick=0,sick;
    bool temp,temp2;
    cin>>n>>milks>>d>>s;
    for(int i=0;i<d;i++){
        cin>>p[i]>>m[i]>>t[i];
    }
    for(int i=0;i<s;i++){
        cin>>sickp[i]>>sickt[i];
    }
    for(int i=1;i<=milks;i++){       //each milk
        sick=0;
        for(int j=0;j<s;j++){    //each sick time
            temp=false;
            for(int k=0;k<d;k++){ //checks if all sick cases drank the milk
                if(p[k]==sickp[j] && m[k]==i && sickt[j]>t[k])
                    temp=true;
            }
            if(!temp){
                break;
            }
        }
        if(temp){
            for(int j=1;j<=n;j++){
                for(int k=0;k<d;k++){
                    if(p[k]==j && m[k]==i){
                        sick++;
                        break;
                    }
                }
            }
        }
        if(sick>maxsick)
            maxsick=sick;
    }
    cout<<maxsick<<endl;
}
//for each sick person,
