#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<vector<string> > arr;

int main()
{
    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        int r, c;
        cin >> r >> c;

        arr.clear();
        arr.resize(r);

        for (int i = 0; i < r; i++)
        {
            string str;
            cin >> str;

            stringstream temp(str);
            string num;
            for (int j = 0 ; j < c; j++)
            {
                getline(temp, num, ',');
                arr[i].push_back(num);
            }
        }


        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < r - 1; i++)
            {
                cout << arr[i][j] << ",";
            }
            cout << arr[r - 1][j] << endl;
        }
    }
}
