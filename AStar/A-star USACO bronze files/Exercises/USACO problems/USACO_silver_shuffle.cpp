#include <iostream>
#include <stdio.h>
using namespace std;

int shuffle[100050],path[100050],counter=0;
bool cycles[100050];

void loop(int cownum){
    //cout<<cownum<<endl;
    int pathi=1,rindex;
    path[0]=cownum;
    bool cont=true;
    while(cont){
        cownum=shuffle[cownum];
        path[pathi++]=cownum;
        /*if(!cycles[path[0]]){
            cout<<"path[0]:"<<path[0]<<endl;
            cycles[path[0]]=true;
            cout<<"cycles[path[0]]:"<<cycles[path[0]]<<endl;
            counter++;
            cout<<"counter:"<<counter<<endl;
        }*/
        //cout<<cownum<<" ";
        if(cycles[path[pathi]]){
            rindex=pathi;
            break;
        }
        for(int i=0;i<pathi;i++){
            if(shuffle[cownum]==path[i]){
                cont=false;
                rindex=i;
                //cout<<i<<" "<<path[i];
                break;
            }
        }
    }
    /*
    cout<<path[0]<<":"<<rindex<<" "<<pathi<<endl;
    for(int i=0;i<pathi;i++)
        cout<<path[i]<<" ";
    cout<<endl;*/
    //cout<<path[0]<<":"<<rindex<<endl;
    for(int i=rindex;i<pathi;i++){
        //cout<<i<<"  ";
        if(!cycles[path[i]]){
            cycles[path[i]]=true;
            counter++;
        }
    }
    //cout<<endl<<endl;
    //cout<<endl;
    /*
    for(int i=0;i<pathi;i++){
        cout<<path[i]<<" ";
    }*/
    //cout<<endl<<endl;
    /*if(shuffle[cownum]==path[0]){
        cycles[path[0]]=true;
        counter++;
        for(int i=)
//        return true;
    }*/
//    else
//        return false;
}

int main(){
    freopen("shuffle.in","r",stdin);
    //freopen("shuffle.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>shuffle[i];
        shuffle[i]--;
    }
    for(int i=0;i<n;i++){
        //cout<<cycles[i]<<" ";
        if(!cycles[i]){
            /*if(loop(i)){
                counter++;
                //cout<<i<<endl;
            }*/
            loop(i);
            //cout<<i<<endl;
        }
    }
    /*
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i<<":"<<cycles[i]<<endl;
    }*/
    cout<<counter<<endl;
}
