#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n,m,minx=100,maxx=0,miny=100,maxy=0,sidelength,black=0;
    string letters;
    cin>>n>>m;
    for(int i=n;i>0;i--){
        cin>>letters;
        for(int j=0;j<m;j++){
            if (letters[j]==66){
                black++;
                if((i)>maxy)
                    maxy=i;
                if((i)<miny)
                    miny=i;
                if((j+1)>maxx)
                    maxx=j+1;
                if((j+1)<minx)
                    minx=j+1;
            }
        }
    }
    if(black==0)
        cout<<1<<endl;
    else{
        sidelength=max(maxx-minx+1,maxy-miny+1);
        if(m>=sidelength && n>=sidelength)//((maxx>=sidelength || (minx+sidelength-1)<=m) && (maxy>=sidelength || (miny+sidelength-1)<=n))
            cout<<sidelength*sidelength-black<<endl;
        else
            cout<<-1<<endl;
    }
}
