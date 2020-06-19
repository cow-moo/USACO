#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

int arr[100];
int score[2];
int main(){
    srand(time(NULL));
    int lower=0,upper,turn=0,sum1=0,sum2=0,case1;
    string input;
    cout<<"Who is going first? computer or player"<<endl;
    cin>>input;
    (input=="computer") ? turn=1 : turn = 0;
    cout<<"How many boxes are there? ";
    cin>>upper;
    if(upper%2==0){
        if(input=="computer")
            case1=1;
        else
            case1=2;
    }
    else{
        if(input=="computer")
            case1=3;
        else
            case1=4;
    }
    upper--;
    cout<<case1<<" case1"<<endl;
    for(int i=lower;i<=upper;i++)
        arr[i]=rand()%15+1;
    input = "0";
    cout<<endl;
    do{
        for(int i=lower;i<=upper;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        if(turn == 0){
            cout<<"Player: left or right"<<endl;
            cin>>input;
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
        }
        else if(turn == 1){
            cout<<"Computer: left or right"<<endl;
            if(sum1==0 && (case1==1 || case1==4)){
                for(int i=lower;i<upper;i+=2)
                    sum1+=arr[i];
                for(int i=lower+1;i<upper;i+=2)
                    sum2+=arr[i];
                if(sum1>sum2){
                    cout<<"left"<<endl;
                    score[turn]+=arr[lower];
                    lower++;
                    turn = 1-turn;
                }
                else{
                    cout<<"right"<<endl;
                    score[turn]+=arr[upper];
                    upper--;
                    turn = 1-turn;
                }
            }
            else if(case1==1 || case1==4){
                cout<<input<<endl;
                if(input=="left"){
                    score[turn]+=arr[lower];
                    lower++;
                    turn = 1-turn;
                }
                else{
                    score[turn]+=arr[upper];
                    upper--;
                    turn = 1-turn;
                }
            }




            else{
            if((arr[upper]-max(arr[upper-1],arr[lower]))>(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"right"<<endl;
                score[turn] += arr[upper];
                upper--;
                turn = 1-turn;
            }
            else if((arr[upper]-max(arr[upper-1],arr[lower]))<(arr[lower]-max(arr[lower+1],arr[upper]))){
                cout<<"left"<<endl;
                score[turn] += arr[lower];
                lower++;
                turn = 1-turn;
            }
            else{
                if(arr[upper]>arr[lower]){
                    cout<<"right"<<endl;
                    score[turn]+=arr[upper];
                    upper--;
                    turn = 1-turn;
                }
                else{
                    cout<<"left"<<endl;
                    score[turn] += arr[lower];
                    lower++;
                    turn = 1-turn;
                }
            }
            }
        }
        cout<<endl<<"Player: "<<score[0]<<endl<<"Computer: "<<score[1]<<endl<<endl;
    }while(upper-lower>=0);
    if(score[0]>score[1]){
        cout<<"The player won "<<score[0]<<" to "<<score[1]<<"!"<<endl;
    }
    else if(score[1]>score[0]){
        cout<<"The computer won "<<score[1]<<" to "<<score[0]<<"!"<<endl;
    }
    else{
        cout<<"The game was a tie!"<<endl;
    }
}

