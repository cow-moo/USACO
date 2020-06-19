#include <iostream>
using namespace std;

int relationships[55][3]; //S:1, D:2
//short relationships[55][55];
int same[20][55];
int diff[20][55];
int cows[20][2]; //[0] is S or D, [1] is which other cow
int n,k,ans=0;
int breed[20];

void assignment(int position){
    for(int i=0;i<position;i++){
        cout<<breed[i]<<" ";
    }
    cout<<endl<<endl;
    if(position==n){
        cout<<"spaghetti"<<endl;
        ans++;
        return;
    }
    bool works;
    for(int i=1;i<=3;i++){
        works=true;
        for(int j=0;j<k;j++){
            if(relationships[j][2]==position){
                cout<<"relationship "<<relationships[j][0]<<" "<<relationships[j][1]<<" "<<relationships[j][2]<<endl;
                if(relationships[j][0]==1 && breed[relationships[j][1]]!=i){
                    works=false;
                    cout<<"not same"<<endl;
                    break;
                }
                if(relationships[j][0]==2 && breed[relationships[j][1]]==i){
                    works=false;
                    cout<<"not diff"<<endl;
                    break;
                }
            }
        }
        if(works){
            breed[position]=i;
            assignment(position+1);
        }
    }
}

int main(){
    int inp1,inp2,kless=0;
    char input;
    bool temp;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>input;
        if(input=='D'){
            relationships[i][0]=2;
            /*cin>>inp1>>inp2;
            inp1--; inp2--;
            while(1){

            }*/
        }
        else{
            relationships[i][0]=1;
        }
        cin>>inp1>>inp2;
        inp1--; inp2--;
        temp=true;
        for(int j=0;j<i;j++){
            if(min(inp1,inp2)==relationships[j][1] && max(inp1,inp2)==relationships[j][2] && relationships[j][0]==relationships[i][0]){
                temp=false;
                kless++;
                break;
            }
        }
        if(!temp)
            continue;
        relationships[i][1]=min(inp1,inp2);
        relationships[i][2]=max(inp1,inp2);
    }
    k-=kless;
    cout<<endl;
    for(int i=0;i<k;i++){
        cout<<relationships[i][0]<<" "<<relationships[i][1]<<" "<<relationships[i][2]<<endl;
    }
    cout<<endl;
    /*for(int i=0;i<k;i++){
        if(relationships[i][0]==2){
            ans*=2;
        }
        //else{
        //    ans*=3;
        //}
    }*/
    //for(int i=0;i<n;i++){
        /*if(cows[i]==0){
            cout<<i;
            ans*=3;
        }*/

    //}
    assignment(0);
    cout<<ans;
}

/*
1 = 2
1!= 3
001
002
110
113
220

121
123
131
132
212
213
231
232
312
313
321
323

*/
