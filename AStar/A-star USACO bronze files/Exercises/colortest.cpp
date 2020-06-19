#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x,int y){
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x,y};
    SetConsoleCursorPosition(hStdout,position);
}

void SetColor(int BackC,int ForgC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0,0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
}

void ClearConsoleToColors(int ForgC,int BackC){
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0,0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wColor);
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        SetConsoleCursorPosition(hStdOut, coord);
    }
    return;
}

/*void SetColor(int ForgC){
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut,&csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut,wColor);
    }
    return;
}*/

int main(){
    char rect=219; string square;
    square+=rect; square+=rect;
    /*SetColor(15,11);
    cout<<square<<endl<<square<<endl<<square<<square<<endl;
    SetColor(0,10);
    SetColor(0,8);
    for(int i=0;i<10;i++){
        gotoxy(1,13+i);
        for(int j=0;j<8;j++)
            cout<<square;
    }*/
    SetColor(0,12);
    cout<<square<<square<<square<<square;
    SetColor(0,15);
}
