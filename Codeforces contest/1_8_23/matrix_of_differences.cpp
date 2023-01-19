#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n * n; i++)
        {
            int row = (i - 1) / n;
            if (row % 2 == 1)
            {
                i = row * n * 2 + n + 1 - i;
            }

            if (i % 2 == 0)
            {
                cout << n * n - i / 2 + 1 << " ";
            }
            else
            {
                cout << i / 2 + 1 << " ";
            }

            if (row % 2 == 1)
            {
                i = row * n * 2 + n + 1 - i;
            }

            if (i % n == 0)
                cout << endl;
        }
    }
}

//row 1: 13
//5, 8
//6, 7

//row 2: 21
//9, 12

//2 * n * (n - 1)
//1 ... n^2 - 1


//row 1
//4, 6
//5, 5
//1 2 3 4 5 6 7 8 9
//1 9 2 8 3 7 4 6 5
//1 9 2
//7 3 8
//4 6 5
//8 7 6 5 4 3 2 1

//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
//1 16 2 15 3 14 4 13 5 12 6 11 7 10 8 9
//1 16 2 15
//13 4 14 3
//5 12 6 11
//9 8 10 7
//15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
