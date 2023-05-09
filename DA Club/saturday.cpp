#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    for (int i = 0; i < 5; i++)
    {
        if (s == days[i])
        {
            cout << 5 - i << endl;
        }
    }
}