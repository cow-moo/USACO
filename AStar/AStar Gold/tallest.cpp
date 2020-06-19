#include <iostream>
using namespace std;

int heights[10050],rlist[10050][2];

int main(){
    int n,index,h,r;
    bool temp;
    cin>>n>>index>>h>>r;
    index--;
    for(int i=0;i<r;i++){
        cin>>rlist[i][0]>>rlist[i][1];
        rlist[i][0]--; rlist[i][1]--;
    }
    for(int i=0;i<n;i++){
        heights[i]=h;
    }
    for(int i=0;i<r;i++){
        //if(heights[rlist[i][0]]>heights[rlist[i][1]])
        //    heights[rlist[i][0]] = heights[rlist[i][1]];
        if(rlist[i][0]<rlist[i][1]){
            temp=true;
            for(int j=rlist[i][0]+1;j<rlist[i][1];j++){
                if(heights[j]>=heights[rlist[i][0]]){
                    temp=false;
                    break;
                }
            }
            if(!temp){
                for(int j=rlist[i][0]+1;j<rlist[i][1];j++)
                    heights[j]--;
            }
        }
        else{
            temp = true;
            for(int j=rlist[i][0]-1;j>rlist[i][1];j--){
                if(heights[j]>=heights[rlist[i][0]]){
                    temp = false;
                    break;
                }
            }
            if(!temp){
                for(int j=rlist[i][0]-1;j>rlist[i][1];j--)
                    heights[j]--;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<heights[i]<<endl;
}
