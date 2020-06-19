#include <iostream>
using namespace std;
int f1(long long x){
    return ((x*x*x)-(4*x)+17)%1000;
}
int f2(long long x){
    return ((-2*x*x)+(5*x)-1)%1000;
}
int f3(long long x){
    return ((3*x*x)-(7*x)+3)%1000;
}
int main(){
    long long n;
    cin>>n;
    cout<<f3(f2(f1(f2(f3(f2(f1(n)))))));
}
