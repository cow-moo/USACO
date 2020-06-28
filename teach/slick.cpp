#include <iostream>
#include <map>
using namespace std;

bool mat [251][251];
//size, instances
map<int, int> instances;
int sz = 0; // reset size everytime

void dfs (int r, int c)
{
   mat [r][c] = 0;
   sz++;
   if (mat[r+1][c] == 1)
   {
       dfs (r + 1, c);
   }
   if (mat[r][c+1] == 1 )
   {
      dfs (r, c + 1);
   }
   if (mat [r][c - 1])
   {
     dfs (r, c - 1);
   }
   if (mat[r-1][c])
   {
       dfs (r-1, c);
   }
}

int main()
{
   int cnt = 0;
   int n, m;
   while (true)
   {
       cnt = 0;
       instances.clear();
       cin >> n >> m;
       if (n == 0 && m == 0)
       {
           break;
       }
       for (int i = 1; i <= n; i++)
       {
           for (int j = 1; j <= m; j++)
           {
               cin >> mat[i][j];
           }
       }
       for (int i = 1; i <= n; i++)
       {
           for (int j = 1; j <= n; j++)
           {
               if (mat[i][j])
               {
                   cnt ++;
                   sz = 0;
                   dfs (i, j);
                   instances[sz]++;
               }
           }
       }
       cout << cnt << endl;
       for (pair<int, int> a : instances) {
            cout << a.first << " " << a.second << endl;
       }
   }
}
