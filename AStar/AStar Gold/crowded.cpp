#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

pair<int,int> cows[50005];//1:pos,2:height
bool crowded[50005];
//vector<pair<int,int> > curcows;//1:pos,2:height
//pair<int,bool> curcows[50005];//1:endpos,2:ifcur

int main(){
    int n,d,counter=0;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>cows[i].first>>cows[i].second;
    sort(cows,cows+n);
    for(int i=0;i<n-1;i++){
        /*for(int j=0;j<curcows.size();j++){
            if(cows[i].first>curcows[j].first)
                curcows.erase(curcows.begin()+j--);
            else if(curcows[j].second>=2*cows[i].second)
                crowded[i]=true;
        }
        curcows.push_back(make_pair(cows[i].first+d,cows[i].second));*/
        /*for(int j=0;j<n;j++){
            if(curcows[j].second){
                if(cows[i].first>curcows[j].first)
                    curcows[j].second=false;
                else if(cows[j].second>=2*cows[i].second)
                    crowded[i]=true;
            }
        }
        curcows[i]=make_pair(cows[i].first+d,true);*/
        for(int j=i+1;j<n;j++){
            if(cows[i].first+d<cows[j].first)
                break;
            else if(cows[j].second>=2*cows[i].second)
                crowded[i]=true;
        }
    }
    for(int i=n-1;i>=0;i--){
        /*for(int j=0;j<curcows.size();j++){
            if(cows[i].first<curcows[j].first)
                curcows.erase(curcows.begin()+j--);
            else if(curcows[j].second>=2*cows[i].second && crowded[i]){
                counter++;
                crowded[i]=false;
            }
        }
        curcows.push_back(make_pair(cows[i].first-d,cows[i].second));*/
        /*for(int j=0;j<n;j++){
            if(curcows[j].second){
                if(cows[i].first<curcows[j].first)
                    curcows[j].second=false;
                else if(cows[j].second>=2*cows[i].second){
                    counter++;
                    crowded[i]=false;
                }
            }
        }
        curcows[i]=make_pair(cows[i].first-d,true);*/
        for(int j=i+1;j<n;j++){
            if(cows[i].first+d<cows[j].first)
                break;
            else if(cows[j].second>=2*cows[i].second && crowded[i]){
                crowded[i]=false;
                counter++;
            }
        }
    }
    cout<<counter<<endl;
}
