#include <iostream>
using namespace std;

int main()
{
   int n;
   cin >> n;
   int togo = n - 1, otogo = n - 1, dir = 0, r = 1, c = 0, counter = 0;
   int spiral[20][20] = {0};

   for (int i = 0; i < n; i++)
   {
       spiral[0][i] = 1;
   }

   while (otogo > 0)
   {
       spiral[r][c] = 1;
       togo--;
       if (counter == 0 && togo == 0)
       {
           togo = otogo;
           counter++;
           dir++;
       }

       else if (counter == 1 && togo == 0)
       {
           otogo -= 2;
           togo = otogo;
           counter = 0;
           dir++;
       }
       if (dir % 4 == 0)
       {
           r++;
       }
       else if (dir % 4 == 1)
       {
           c++;
       }
       else if (dir % 4 == 2)
       {
           r--;
       }
       else if (dir % 4 == 3)
       {
           c--;
       }
   }
   if (n % 2 == 0)
   {
       spiral[n / 2][n / 2] = 0;
   }

   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < n; j++)
       {
           if (spiral[i][j] == 0)
           {
               cout << " ";
           }
           else if (spiral[i][j] == 1)
           {
               cout << "*";
           }
       }
       cout << endl;
   }
}
