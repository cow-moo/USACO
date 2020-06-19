#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const float grav = 9.8;
int main()
{
    float dist,dist_fallen = 0;
    cout<<"Enter the initial height of the tower in meters: ";
    cin>>dist;
    for(int i = 0;i<=5;i++){
        dist_fallen = grav*i*i/2;
        if(dist_fallen>=dist){
            cout<<"At "<<i<<" seconds, the ball is on the ground."<<endl;
        }
        else{
            cout<<"At "<<i<<" seconds, the ball is at height: "<<dist-dist_fallen<<" meters"<<endl;
        }

    }
}
