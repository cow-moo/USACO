#include <iostream>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int height,gemcount=0;
string maze[1000];
int monsterx[1000],monstery[1000];

void printmaze(){
    int gems=gemcount;
    string mazestr="\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    string num="",temp="";
    mazestr+="Gems left: ";
    while(gems>0){
        temp=(gems%10)+'0';
        num=temp+num;
        gems/=10;
    }
    mazestr+=num;
    mazestr+="\n";
    for(int i=0;i<height;i++){
        mazestr=mazestr+maze[i]+"\n";
    }
    cout<<mazestr;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    ifstream fin ("pacman.txt");
    int pacx,pacy,origpx,origpy,mcount=0,random,quit;//0 is not win,1 is dead,2 is quit
    char input;
    fin>>height;
    for(int i=0;i<height;i++){
        fin>>maze[i];
        for(int j=0;j<maze[i].length();j++){
            if(maze[i][j]=='P'){
                pacx=j;
                pacy=i;
                origpx=j;
                origpy=i;
            }
            if(maze[i][j]=='G')
                gemcount++;
            if(maze[i][j]=='M'){
                monsterx[mcount]=j;
                monstery[mcount]=i;
                mcount++;
            }
        }
    }
    for(int lives=3;lives>0;lives--){
        quit=0;
        while(1){
            printmaze();
            input = getch();
            if(input!='w'&&input!='a'&&input!='s'&&input!='d')
                continue;
            for(int i=0;i<mcount;i++){
                random=rand()%4;
                if(random==0){
                    if(maze[monstery[i]-1][monsterx[i]]=='.')
                        swap(maze[monstery[i]][monsterx[i]],maze[monstery[i]--][monsterx[i]]);
                }
                else if(random==1){
                    if(maze[monstery[i]+1][monsterx[i]]=='.')
                        swap(maze[monstery[i]][monsterx[i]],maze[monstery[i]++][monsterx[i]]);
                }
                else if(random==2){
                    if(maze[monstery[i]][monsterx[i]+1]=='.')
                        swap(maze[monstery[i]][monsterx[i]],maze[monstery[i]][monsterx[i]++]);
                }
                else if(random==3){
                    if(maze[monstery[i]][monsterx[i]-1]=='.')
                        swap(maze[monstery[i]][monsterx[i]],maze[monstery[i]][monsterx[i]--]);
                }
            }
            if(input=='w'){
                if(maze[pacy-1][pacx]=='.')
                    swap(maze[pacy][pacx],maze[pacy--][pacx]);
                else if(maze[pacy-1][pacx]=='E' && gemcount==0){
                    maze[pacy][pacx]='.';
                    maze[--pacy][pacx]='P';
                    break;
                }
                else if(maze[pacy-1][pacx]=='M'){
                    maze[pacy][pacx]='.';
                    quit=1;
                    break;
                }
                else if(maze[pacy-1][pacx]=='G'){
                    gemcount--;
                    maze[pacy][pacx]='.';
                    pacy--;
                    maze[pacy][pacx]='P';
                }
            }
            else if(input=='s'){
                if(maze[pacy+1][pacx]=='.')
                    swap(maze[pacy][pacx],maze[pacy++][pacx]);
                else if(maze[pacy+1][pacx]=='E' && gemcount==0){
                    maze[pacy][pacx]='.';
                    maze[++pacy][pacx]='P';
                    break;
                }
                else if(maze[pacy+1][pacx]=='M'){
                    maze[pacy][pacx]='.';
                    quit=1;
                    break;
                }
                else if(maze[pacy+1][pacx]=='G'){
                    gemcount--;
                    maze[pacy][pacx]='.';
                    pacy++;
                    maze[pacy][pacx]='P';
                }
            }
            else if(input=='d'){
                if(maze[pacy][pacx+1]=='.')
                    swap(maze[pacy][pacx],maze[pacy][pacx++]);
                else if(maze[pacy][pacx+1]=='E' && gemcount==0){
                    maze[pacy][pacx]='.';
                    maze[pacy][++pacx]='P';
                    break;
                }
                else if(maze[pacy][pacx+1]=='M'){
                    maze[pacy][pacx]='.';
                    quit=1;
                    break;
                }
                else if(maze[pacy][pacx+1]=='G'){
                    gemcount--;
                    maze[pacy][pacx]='.';
                    pacx++;
                    maze[pacy][pacx]='P';
                }
            }
            else if(input=='a'){
                if(maze[pacy][pacx-1]=='.')
                    swap(maze[pacy][pacx],maze[pacy][pacx--]);
                else if(maze[pacy][pacx-1]=='E' && gemcount==0){
                    maze[pacy][pacx]='.';
                    maze[pacy][--pacx]='P';
                    break;
                }
                else if(maze[pacy][pacx-1]=='M'){
                    maze[pacy][pacx]='.';
                    quit=1;
                    break;
                }
                else if(maze[pacy][pacx-1]=='G'){
                    gemcount--;
                    maze[pacy][pacx]='.';
                    pacx--;
                    maze[pacy][pacx]='P';
                }
            }
            else if(input=='q'){
                cout<<"Are you sure you want to quit? Y or N"<<endl;
                cin>>input;
                if(input=='Y' || input=='y' || input=='N' || input=='n'){
                    quit=2;
                    break;
                }
            }
        }
        printmaze();
        if(quit==1){
            cout<<"You died!"<<endl;
            if(lives==1){
                cout<<"Game over!"<<endl;
                cin.get();
                cin.get();
                break;
            }
        }
        else if(quit==0){
            cout<<"You won with "<<lives<<" live(s) left!"<<endl;
            cin.get();
            cin.get();
            break;
        }
        else if(quit==2){
            cout<<"You quit the game."<<endl;
            break;
        }
        maze[origpy][origpx]='P';
        pacx=origpx;
        pacy=origpy;
        cout<<"You have "<<lives-1<<" lives."<<endl<<endl;
        cout<<"Press any key to continue"<<endl;
        input = getch();
    }
}
