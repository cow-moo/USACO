#include <iostream>
using namespace std;

string arr[21];
int main(){
    int n,x,y,direction=0; //0 is left, 1 is down, 2 is right, 3 is up (mod 4)
    cin>>n;
    x=n-1;
    y=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            arr[i]+=" ";
    }
    while(direction!=n){
        arr[y][x] = '*';
        if(direction%4==0){
            if(x-2>=0){
                if(arr[y][x-2]!='*')
                    x--;
                else
                    direction++;
            }
            else if(x>0)
                x--;
            else
                direction++;
        }
        else if(direction%4==1){
            if(n-y>=2){
                if(arr[y+2][x]!='*')
                    y++;
                else
                    direction++;
            }
            else if(y<n-1)
                y++;
            else
                direction++;
        }
        else if(direction%4==2){
            if(x+2<=n){
                if(arr[y][x+2]!='*')
                    x++;
                else
                    direction++;
            }
            else if(x<n-1)
                x++;
            else
                direction++;
        }
        else if(direction%4==3){
            if(y-2>=0){
                if(arr[y-2][x]!='*')
                    y--;
                else
                    direction++;
            }
            else if(y>0)
                y--;
            else
                direction++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}
