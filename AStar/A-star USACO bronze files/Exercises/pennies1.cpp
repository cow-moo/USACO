#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

int arr[100];
int score[2];
int main(){
    srand(time(NULL));
    int lower=0,upper,turn=0;
    string input;
    cin>>upper;
    upper--;
    for(int i=lower;i<=upper;i++)
        arr[i]=rand()%15+1;
    cout<<endl;
    do{
        for(int i=lower;i<=upper;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        cout<<"Player "<<turn+1<<": left or right"<<endl;
        cin>>input;
        cout<<endl;
        if(input=="right"){
            score[turn] += arr[upper];
            upper--;
            turn = 1-turn;
        }
        else if(input=="left"){
            score[turn] += arr[lower];
            lower++;
            turn = 1-turn;
        }
        else{
            cout<<"Incorrect input. Please try again.\n"<<endl;
        }
        cout<<"Player 1: "<<score[0]<<endl<<"Player 2: "<<score[1]<<endl<<endl;
    }while(upper-lower>=0);
    if(score[0]>score[1]){
        cout<<"Player 1 won "<<score[0]<<" to "<<score[1]<<"!"<<endl;
    }
    else if(score[1]>score[0]){
        cout<<"Player 2 won "<<score[1]<<" to "<<score[0]<<"!"<<endl;
    }
    else{
        cout<<"The game was a tie!"<<endl;
    }
}
