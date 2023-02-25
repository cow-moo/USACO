#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    long long horizontal=0;
    long long vertical=0;
    int n=0;

    cin>>n;
    int length[n];

    for(int i=0;i<n;i++){
        cin>>length[i];
    }
    
    sort(length, length + n);

    //3
    //1
    //4, 2

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
        {
        horizontal+=length[i]; 
        }
        else
        {
        vertical+=length[i];
        }
    }
    cout<<horizontal*horizontal+vertical*vertical;

    

   
}