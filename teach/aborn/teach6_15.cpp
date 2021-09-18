#include <iostream>
using namespace std;

/*
x += 5       x = x + 5
x -= 5       x = x - 5
x *= 5       x = x * 5
x /= 5       x = x / 5
x %= 5       x = x % 5
x++          increment x by one; equivalent to x = x + 1
x--          decrement x by one; equivalent to x = x - 1

for loops
for (initialize counter; condition that is always true when the loop is running; increment counter)
{
    //code that will loop
}
for (int i = 0; i < 10; i++)
{

}
*/

int main()
{

    int counter = 0;

    while (counter < 5)
    {
        cout << "a" << endl;

        counter++;
    }


    ////


    for (int i = 0; i < 5; i++)
    {
        cout << "b" << endl;
    }

    cout << "done" << endl;


    ////


    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << i << " " << j << endl;
        }
    }
}

/*
int a, b, res = 1;
cin >> a >> b;
put a^b in res, print res

int n, res = 0;
cin >> n;
calculate 1 + 2 + 3... + n and print


write a program to read n from keyboard, then read n numbers from the keyboard and find their sum and average (and print)

take in n, make a square with height n
******
******
******
******
******
******

print out 1 line of n asterisks
******

take in n, make a triangle with height n
*      line 0 == 1 asterisk
**     line 1 == 2 asterisk
***    line 2 == 3
****   line 3 == 4
*****  line 4 == 5

i is line #

*****  line 0 == 5 asterisks
****   line 1 == 4
***    line 2 == 3
**     line 3 == 2
*      line 4 == 1
i + # = n

*/
