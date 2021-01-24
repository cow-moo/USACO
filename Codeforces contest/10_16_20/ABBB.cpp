#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        string str;
        cin >> str;

        int numa = 0, numb = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'A')
                numa++;
            if (str[i] == 'B')
            {
                if (numa > 0)
                    numa--;
                else
                    numb++;
            }
        }

        cout << (numb % 2) + numa << endl;
    }
}
