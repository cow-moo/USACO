#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans = 0;
    for(int i = 0;i<=100;i++){
        if((i>=a && i<=b) || (i>=c && i<=d))
            ans++;
    }
    cout<<ans<<endl;
}
