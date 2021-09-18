#include <iostream>
using namespace std;

/*
Strings store text
string str;    declaration
str = "asdf";  assignment

Note: You cannot do math on strings storing numbers ("1234" + "100" does not give "1334" or 1334), they are simply text

+ concatenation; the strings are glued together to make a longer string
string str = "My name is " + "Jane.";
str will have the value "My name is Jane."

== equal
!= not equal
>  gives true/false based on alphabetical order
<
>=
<=

Characters store a single character
'a' char
"a" string
char c;   declaration
c = 'a';  assignment
==
!=
>
<
>=
<=

Strings can be treated like an array of characters
string str = "abcdefghijklmnopqrstuvwxyz";
str[0] is a char representing 'a', str[1] is a char representing 'b', etc.

You can think of a string like a box that stores a row of boxes (array) inside of it

str.length();
^
specify which variable (only works on strings)
     ^
    ask the variable/box to tell you how long the string is

You can think of functions like this like a button in the box that takes in some values and spits out some values. In this case, str.length() takes no inputs
but spits out an integer representing length

A substring of a string is a chunk of characters taken from the middle.
E.g. "lloworl" is a substring of "Helloworld!", starting at index 2 and with length 7

str.substr(2, 7);
^
specify which variable
    ^
    specify the starting position and length

This function is a button in the box that takes in two numbers and spits out another string representing the desired substring
*/

int main()
{
/*
    //{'a', 'b', 'c', 'd', 'e', 'f'}
    string var = "abcdefg";
    //var[2] = '3';
    //cout << var[2] << endl;

    cout << var << " " << var.length() << endl;

    cout << var[var.length() / 2] << endl;
*/

//    string str = "asdf";
//    for (int i = 0; i < str.length(); i++)
//    {
//        cout << str[i] << ", ";
//    }

    string str1;
    cin >> str1;
    cout << str1;

    "Helloworld!"
      "lloworl"

    str.length();

    for (int i = a; i < a + b; i++)
    {
        cout << str[i];
    }
    cout << str.substr(a, b);
/*
    int n, arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
*/
}
