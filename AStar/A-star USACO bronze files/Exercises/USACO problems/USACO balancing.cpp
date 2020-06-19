#include <iostream>
using namespace std;

int x[100],y[100];
int main(){
    int n,b,m,uleft,uright,lleft,lright,vertical,horizontal,maxregion;
    cin>>n>>b;
    for(int i=0;i<n;i++)
        cin>>x[i]>>y[i];
    m = n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vertical = x[i]+1;
            horizontal = y[j]+1;
            uleft = 0;
            uright = 0;
            lleft = 0;
            lright = 0;
            for(int k=0;k<n;k++){
                if(x[k]<vertical && y[k] < horizontal){
                    lleft++;
                }
                if(x[k]<vertical && y[k]>horizontal){
                    uleft++;
                }
                if(x[k]>vertical && y[k]<horizontal){
                    lright++;
                }
                if(x[k]>vertical && y[k]>horizontal){
                    uright++;
                }
            }
            maxregion=0;
            if(uleft>maxregion){
                maxregion=uleft;
            }
            if(uright>maxregion){
                maxregion=uright;
            }
            if(lleft>maxregion){
                maxregion=lleft;
            }
            if(lright>maxregion){
                maxregion=lright;
            }
            if(maxregion<m){
                m=maxregion;
            }
        }
    }
    cout<<m;
}
