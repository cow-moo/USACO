#include <iostream>
#include <stdlib.h>
using namespace std;
bool isbetween(int x,int y,int a){
    if((a>=x && a<=y)||(a>=y && a<=x))
        return true;
    else
        return false;
}
int oldxy[105][2],newxy[105][2],steparr[105]; //0:x 1:y
int findtime(int i){
    int sum=0;
    for(int j=0;j<=i;j++){
        sum+=steparr[j];
    }
    return sum;
}
int main(){
    int n,x=0,y=0,ans=1000000000;
    char direction;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>direction>>steparr[i];
        oldxy[i][0]=x;
        oldxy[i][1]=y;
        if(direction=='N')
            y+=steparr[i];
        else if(direction=='S')
            y-=steparr[i];
        else if(direction=='E')
            x+=steparr[i];
        else if(direction=='W')
            x-=steparr[i];
        newxy[i][0]=x;
        newxy[i][1]=y;
    }
    for(int i=0;i<n;i++){//i is the vertical line
        for(int j=0;j<n;j++){//j is the horizontal line
            if(abs(i-j)>1 && oldxy[i][0]==newxy[i][0] && oldxy[j][1]==oldxy[j][1] && isbetween(oldxy[i][1],newxy[i][1],oldxy[j][1]) && isbetween(oldxy[j][0],newxy[j][0],oldxy[i][0])){
                if(abs(findtime(i)-abs(newxy[i][1]-newxy[j][1])-(findtime(j)-abs(newxy[j][0]-newxy[i][0])))<ans)
                    ans=abs(findtime(i)-abs(newxy[i][1]-newxy[j][1])-(findtime(j)-abs(newxy[j][0]-newxy[i][0])));
            }
        }
    }
    if(ans<1000000000)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}
