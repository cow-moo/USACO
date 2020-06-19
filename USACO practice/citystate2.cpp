#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<string,int> citystate;

int main(){
    freopen("citystate.in","r",stdin);
    freopen("citystate.out","w",stdout);
    int n;
    string city,state;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>city>>state;
        if(city.substr(0,2)!=state){
            string key=city.substr(0,2)+state;
            if(!citystate.count(key))
                citystate.insert(pair<string,int>(key,0));
            citystate.insert(pair<string,int>(key,citystate.at(key)+1));
        }
    }
    int counter=0;
    for(map<string,int>::iterator it=citystate.begin();it!=citystate.end();++it){
        string otherkey = it->first.substr(2) + it->first.substr(0,2);
        if(citystate.count(otherkey))
            counter++;
    }
    cout<<counter/2<<endl;
}
