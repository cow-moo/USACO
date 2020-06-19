#include <iostream>
using namespace std;

int main()
{
    int b1,b2,s1,s2,g1,g2,p1,p2,b_to_s,s_to_g,g_to_p;
    cin>>b1>>b2;
    cin>>s1>>s2;
    cin>>g1>>g2;
    cin>>p1>>p2;
    g2+=p2-p1;
    g_to_p+=p2-p1;
    s2+=g2-g1;
    s_to_g+=g2-g1;
    b2+=s2-s1;
    b_to_s+=s2-s1
    cout<<b_to_s<<endl
        <<s_to_g<<endl
        <<g_to_p<<endl;
}
