#include <iostream>
#include <utility>
using namespace std;

int n;
pair<int,int> pastures[155]; //.first is y,.second is x
bool adj[155][155];

int main(){
    string input;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pastures[i].second>>pastures[i].first;
    }
    for(int i=0;i<n;i++){
        cin>>input;
        for(int j=0;j<n;j++){
            adj[i][j]=input[j]-'0';
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }*/
}
