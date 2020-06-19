#include <iostream>
#include <set>
using namespace std;

int skyline[50005];
set<int> buildings;

int main(){
    int n,w,input,counter=0;
    cin>>n>>w;
    for(int i=0;i<n;i++){
        cin>>input;
        cin>>skyline[i];
    }
    buildings.insert(0);
    for(int i=0;i<n;i++){
        if(buildings.count(skyline[i])==0){
            buildings.insert(skyline[i]);
            counter++;
            buildings.erase(++buildings.find(skyline[i]),buildings.end());
        }
        else
            buildings.erase(++buildings.find(skyline[i]),buildings.end());
    }
    cout<<counter<<endl;
}
