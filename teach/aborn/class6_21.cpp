#include <iostream>
#include <stdio.h>
using namespace std;

/*
http://www.asciitable.com/
Characters can actually be used like integers; each character corresponds to a number code from the ASCII table
Ex: 'A' is 65, 'b' is 98, '#' is 35, '0' is 48

You can use this property to manipulate characters.

check if a character is a lowercase letter, uppercase letter, or something else
    if (c >= 'a' && c <= 'z')
    {
        cout << "lowercase" << endl;
    }
    else if (c >= 'A' && c  <= 'Z')
    {
        cout << "uppercase" << endl;
    }
    else
    {
        cout << "not a letter" << endl;
    }

You can also convert a letter into a number such that 'a' corresponds to 0, 'b' corresponds to 1, ..., 'z' corresponds to 25
(c - 'a') will do this (try looking at the ASCII table to see how this works)

You can cast an integer to a character. If you wanted to print the character 'H', you could do cout << (char)72 << endl;

If we do (char)(c - 'a' + 'A'), this will convert any lowercase letter to an uppercase letter.
In a similar manner, (c - 'A' + 'a') will convert any uppercase letter to a lowercase letter.

write a program that converts all letters to uppercase in a given string
    I8-10caKes!   =>   I8-10CAKES!
write a program that reads a string and writes the number of digits in that string to the screen

Sometimes you will also need to input from and output to text files (old USACO problems). The problem will generally ask you to input from __.in
and __.out, where __ is the name of the problem. These are text files.
To input/output from text files:
1. #include <stdio.h> in the line after #include <iostream>
2. freopen("__.in", "r", stdin); at the beginning of your int main()
3. freopen("__.out", "w", stdout); at the beginning of your int main()
The second step tells the computer to read from __.in using stdin (which represents cin)
The third step tells the computer to write to __.out using stdout (which represents cout)


Lastly, always try to declare arrays globally, meaning you put it before the int main() function:
int arr[1000]; //1000 is the maximum size of n

int main()
{
    int n;
    cin >> n;
    //do not declare an array here
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

In USACO problems, they will always give you bounds on the input. They may say 1 <= n <= 1000, which tells you you should make your array size 1000.
*/

//bool isPrime(int num)
//{
//
//    return true;
//    return false;
//}

bool prime[1000]; //7 * 2, 7 * 3, 7 * 4.. ,7 * 7
//2, 3, 4, 5, 6, 7, 8, 9, ..., 23
//1, 1, 0, 1, 0, 1, 0, 0,
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        prime[i] = true;

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            //cout << i << endl;
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    int counter = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
            counter++;
    }
    cout << counter << endl;
//    int n;
//    cin >> n;
//
//    int counter = 0;
//    for (int i = 2; i < n; i++)
//    {
//        if (isPrime(i))
//            counter++;
//    }
    //char c;
    //cin >> c;

//    int charNum = c - 'a';
//    cout << (char)(charNum + 'A') << endl;
//    cout << (char)72 << endl;

//    if (c >= 'a' && c <= 'z')
//    {
//        cout << "lowercase" << endl;
//    }
//    else if (c >= 'A' && c  <= 'Z')
//    {
//        cout << "uppercase" << endl;
//    }
//    else
//    {
//        cout << "not a letter" << endl;
//    }

//write a program that converts all letters to uppercase in a given string
//I8-10caKes!   =>   I8-10CAKES!
//write a program that reads a string and writes the number of digits in that string to the screen
    //for (int i = 0; i < 10; i++)
    //{
//        for (int j = 0; j < 10; j++)
//        {
//            cout << 'a';
//            if (j == 7)
//            {
//                break;
//            }
//            cout << j << endl;
//        }
    //}

    //freopen("class6_21.in", "r", stdin); //cin
    //freopen("cows.out", "w", stdout); //cout

//    int n;
//    cin >> n;
//    cout << n + 5 << endl;

    //write a program which finds the number of primes that are less than the given number
}
