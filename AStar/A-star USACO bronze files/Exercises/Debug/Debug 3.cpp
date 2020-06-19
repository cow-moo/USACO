/*
Find the two largest numbers given n integers and output them

Example:
Input:
3
1 2 3

Output:
3 2
*/

#include <iostream>

using namespace std;

int n,x,a=0,b=0;
int main() {
    cin>>n;
    for(int i=0;i<=n;i++) {  //should be i<n not i<=n
        cin>>x;
        if(x>a) {
            b=a;
            a=x;
        }
        else if(x>b) { //add this else if
            b=x;
        }
    }
    cout<<a<<" "<<b<<endl;
    return 0;
}
