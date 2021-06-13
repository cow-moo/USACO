#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> shift;
vector<int> dir;

int main()
{
    int t;
    cin >> t;
    cin.get();

    for (int z = 0; z < t; z++)
    {
        shift.clear();
        dir.clear();

        string message;
        getline(cin, message);

        string line;
        getline(cin, line);

        int inp;
        istringstream iss(line);
        while (iss >> inp)
        {
            shift.push_back(inp);
        }

        getline(cin, line);
        istringstream iss2(line);
        while (iss2 >> inp)
        {
            inp = 2 * inp - 1;
            //cout << inp << endl;
            dir.push_back(inp);
        }

        int nonChar = 0;

        for (int i = 0; i < message.length(); i++)
        {
            if (message[i] >= 'A' && message[i] <= 'Z')
            {
                int num = message[i] - 'A';
                num += -1 * shift[(i - nonChar) % shift.size()] * dir[(i - nonChar) % dir.size()];
                num += 52;
                num %= 26;
                //cout << num << endl;
                cout << (char)('a' + num);
            }
            else
            {
                cout << message[i];
                nonChar++;
            }
        }
        cout << endl;
    }

    //cin.get();
}
