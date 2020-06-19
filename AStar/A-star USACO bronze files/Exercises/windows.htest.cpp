#include <iostream>
#include <windows.h>
using namespace std;

int main(){
    while(1){
        if(GetAsyncKeyState(0x43)){
            cout<<"cool"<<endl;
        }
        if(GetAsyncKeyState(0x44))
            cout<<"not cool"<<endl;
        Sleep(125);
    }
}
