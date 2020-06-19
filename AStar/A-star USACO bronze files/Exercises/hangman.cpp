#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;

string body[2]={" ","|"},larm[2]={" ","/"},rarm[2]={" ","\\"},lleg[2]={" ","/"},rleg[2]={" ","\\"};
string guessedchar[30];
string guessedwords[100];
int main(){
    ifstream matthew ("dict.txt");
    srand(time(NULL));
    string secret;
    for(int i=0;i<=rand()%218;i++){
        getline(matthew,secret);
    }
    //cout<<secret<<endl;
    int mistakes=0,guessedcharcount=0,guessedwordcount=0;
    string input;
    bool temp=false;
    while(1){
        cout<<" _____"<<endl
            <<"|     | "<<endl
            <<"|     | "<<endl
            <<"|     O "<<endl
            <<"|    "<<larm[mistakes>=2]<<body[mistakes>=1]<<rarm[mistakes>=3]<<endl
            <<"|    "<<lleg[mistakes>=4]<<" "<<rleg[mistakes>=5]<<endl
            <<"|        "<<endl
            <<"|_______"<<endl;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==' ')
                cout<<"  ";
            else if(secret[i]==','||secret[i]==','||secret[i]=='.'||secret[i]=='!'||secret[i]=='?'||secret[i]=='-')
                cout<<secret[i];
            else{
                temp=true;
                for(int j=0;j<guessedcharcount;j++){
                    if(secret[i]==guessedchar[j][0]){
                        cout<<secret[i]<<" ";
                        temp=false;
                    }
                }
                if(temp)
                    cout<<"_ ";
            }
        }
        cout<<endl<<endl<<"Guessed characters: ";
        for(int i=0;i<guessedcharcount;i++)
            cout<<guessedchar[i]<<" ";
        cout<<endl<<"Guessed words: ";
        cout<<guessedwords[0];
        for(int i=1;i<guessedwordcount;i++)
            cout<<", "<<guessedwords[i];
        if(mistakes==5){
            cout<<endl<<endl<<"he's dead jim"<<endl<<endl<<"The phrase/word was: "<<secret<<endl;
            break;
        }
        temp = true;
        for(int i=0;i<secret.length();i++){
            temp=false;
            if(secret[i]<'a'||secret[i]>'z')
                continue;
            for(int j=0;j<guessedcharcount;j++){
                if(guessedchar[j][0]==secret[i]){
                    temp=true;
                    break;
                }
            }
            if(!temp)
                break;
        }
        if(temp){
            cout<<endl<<endl<<"You got the word!"<<endl;
            break;
        }
        cout<<endl<<endl<<"Guess a letter or the word: ";
        getline(cin,input);
        cout<<endl;
        if(input.length()==secret.length()){
            if(input==secret){
                cout<<"You got it!"<<endl;
                break;
            }
            else{
                cout<<"That is not the word."<<endl;
                mistakes++;
            }
            guessedwords[guessedwordcount]=input;
            guessedwordcount++;
        }
        else if(input.length()==1){
            temp = false;
            for(int i=0;i<guessedcharcount;i++){
                if(guessedchar[i]==input)
                    temp=true;
            }
            if(temp){
                cout<<"You already guessed that."<<endl;
                continue;
            }
            if(secret.find(input)>secret.length()){
                cout<<"That letter isn't in the secret word."<<endl;
                mistakes++;
            }
            else{
                cout<<"You got a letter."<<endl;
            }
            guessedchar[guessedcharcount]=input;
            guessedcharcount++;
        }
        else{
            cout<<"Incorrect input."<<endl;
        }
    }
}
