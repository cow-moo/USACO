#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

pair<pair<int,bool>,pair<int,int> > changepts[2005];//bottom then top
multiset<pair<int,int> > bottomsorted;//bottom then top
multiset<pair<int,int> > topsorted;   //top then bottom
//        x   add/del   bot top
int main(){
    int n,input1,input2,input3,input4,curgrass=0,total=0,nextpt=0;
    bool responsible;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input1>>input2>>input3>>input4;
        changepts[2*i]=make_pair(make_pair(input1,false),make_pair(input4,input2));
        changepts[2*i+1]=make_pair(make_pair(input3,true),make_pair(input4,input2));
    }
    sort(changepts,changepts+2*n);
    //for(int i=0;i<2*n;i++)
    //    cout<<changepts[i].first.first<<" "<<changepts[i].first.second<<" "<<changepts[i].second.first<<" "<<changepts[i].second.second<<endl;
    for(int i=0;i<2*n-1;i++){
        if(changepts[i].first.second==0){//add
            responsible=true;
            for(multiset<pair<int,int> >::iterator it=bottomsorted.begin();it!=bottomsorted.end();it++){
                //cout<<(*it).first<<" "<<(*it).second<<endl;
                if((*it).first>changepts[i].second.first){
                    nextpt=(*it).first;
                    break;
                }
                if((*it).second>=changepts[i].second.first){
                    responsible=false;
                    break;
                }
            }
            if(responsible){
                curgrass+=min(nextpt,changepts[i].second.second)-changepts[i].second.first;
            }
            bottomsorted.insert(changepts[i].second);
            responsible=true;
            for(multiset<pair<int,int> >::reverse_iterator it=topsorted.rbegin();it!=topsorted.rend();it++){
                //cout<<(*it).first<<" "<<(*it).second<<endl;
                if((*it).first<changepts[i].second.second){
                    nextpt=(*it).first;
                    break;
                }
                if((*it).second<=changepts[i].second.second){
                    responsible=false;
                    break;
                }
            }
            //cout<<responsible<<endl;
            if(responsible && nextpt>changepts[i].second.first){
                curgrass+=changepts[i].second.second-nextpt;
                //curgrass+=min(nextpt,changepts[i].second.second);
            }
            topsorted.insert(make_pair(changepts[i].second.second,changepts[i].second.first));
            total+=(changepts[i+1].first.first-changepts[i].first.first)*curgrass;
            cout<<curgrass<<endl;
        }
        else{//del
            responsible=true;
            for(multiset<pair<int,int> >::iterator it=bottomsorted.begin();it!=bottomsorted.end();it++){
                //cout<<(*it).first<<" "<<(*it).second<<endl;
                if((*it).first>changepts[i].second.first){
                    nextpt=(*it).first;
                    break;
                }
                if((*it).second>=changepts[i].second.first){
                    responsible=false;
                    break;
                }
            }
            if(responsible){
                curgrass-=min(nextpt,changepts[i].second.second)-changepts[i].second.first;
            }
            bottomsorted.erase(changepts[i].second);
            responsible=true;
            for(multiset<pair<int,int> >::reverse_iterator it=topsorted.rbegin();it!=topsorted.rend();it++){
                //cout<<(*it).first<<" "<<(*it).second<<endl;
                if((*it).first<changepts[i].second.second){
                    nextpt=(*it).first;
                    break;
                }
                if((*it).second<=changepts[i].second.second){
                    responsible=false;
                    break;
                }
            }
            //cout<<responsible<<endl;
            if(responsible && nextpt>changepts[i].second.first){
                curgrass-=changepts[i].second.second-nextpt;
                //curgrass+=min(nextpt,changepts[i].second.second);
            }
            topsorted.erase(make_pair(changepts[i].second.second,changepts[i].second.first));
            total+=(changepts[i+1].first.first-changepts[i].first.first)*curgrass;
            cout<<curgrass<<endl;
        }
    }
}
