#include <iostream>
using namespace std;

string str,split[25],minimum="NO SOLUTION";
int l,n;

void recurse(int start,string curstr){
    int tempstart=start;
    string tempstr=curstr;
    for(int i=1;i<=l-start;i++){
        for(int j=0;j<n;j++){
            if(split[j].length()!=i)
                continue;
            int equals=true;
            for(int k=0;k<i;k++){
                if(str[start+k]!=split[j][k] && str[start+k]!='?')
                    equals=false;
            }
            if(equals){
                curstr=curstr+split[j];
                if(curstr.length()==l && curstr<minimum){
                    minimum=curstr;
                }
                else{
                    recurse(start+i,curstr);
                    curstr=tempstr;
                    start=tempstart;
                }
            }
        }
    }
}

int main(){
    cin>>l>>n>>str;
    for(int i=0;i<n;i++){
        cin>>split[i];
    }
    recurse(0,"");
    cout<<minimum<<endl;
}
