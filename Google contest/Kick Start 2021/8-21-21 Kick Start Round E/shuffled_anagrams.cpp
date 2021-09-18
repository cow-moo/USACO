#include <iostream>
#include <algorithm>
using namespace std;

int arr[10050];
string str;

bool comp(int a, int b)
{
    return str[a] < str[b];
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        cin >> str;

        for (int i = 0; i < str.length(); i++)
        {
            arr[i] = i;
        }

        sort(arr, arr + str.length(), comp);

        cout << "Case #" << z << ": ";

//        bool bad = false;
//        for (int i = 0; i < str.length() / 2; i++)
//        {
//            swap(str[arr[i]], str[arr[str.length() - 1 - i]]);
//            if (str[arr[i]] == str[arr[str.length() - 1 - i]])
//            {
//                cout << "IMPOSSIBLE" << endl;
//                bad = true;
//                break;
//            }
//        }
//        if (bad)
//            continue;
        string ans = str;
        bool bad = false;
        for (int i = 0; i < str.length(); i++)
        {
            int next = (i + str.length() / 2) % str.length();
            ans[arr[i]] = str[arr[next]];
            if (str[arr[i]] == str[arr[next]])
            {
                cout << "IMPOSSIBLE" << endl;
                bad = true;
                break;
            }

        }
        if (bad)
            continue;
        cout << ans << endl;

        //cout << str << endl;
//        for (int i = 0; i < str.length(); i++)
//        {
//            //cout << arr[i];
//            cout << str[arr[i]];
//        }
//        cout << endl;
    }
}
