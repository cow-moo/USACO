#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
//1,80,100
int main(){
    srand(time(NULL));
    int secretnumber,input,counter=0,upper,lower,guess,inarow,x=0;
    upper = 101;
    lower = 0;
    cout<<"Think of a number (between 1 and 100) for the computer to guess."<<endl;
    cout<<"If the number is lower, enter -1, if the number is greater, enter 1. If the number is right, enter 0."<<endl;
    do
    {
        if (counter%2==0)
            guess = (upper+lower)/2;
        else
            guess = rand() % (upper-lower-1) + lower + 1;
        cout<<guess<<endl;
        cin>>input;
        /*if (x == 0)
            x = input;
        else{
            if (x==input)
                inarow++;
        }
        if (inarow == 3){
            if (x = 1)
                guess = 100;
            else
                guess = 1;
        }*/
        if (input==-1)
            upper = guess;
        else if (input==1)
            lower = guess;
        counter++;
    }while(input!=0);
    cout<<"The computer took "<<counter<<" tries!"<<endl;
}

