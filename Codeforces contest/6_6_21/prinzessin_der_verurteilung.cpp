#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

string suffix[1005];

int getNum(string a)
{
    int res = 0;
    int cur = 1;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        res += cur * (a[i] - 'a');
        cur *= 26;
    }
    return res;
}

string getStr(int a, int length)
{
    string res = "";
    for (int i = 0; i < length; i++)
    {
        res = (char)(a % 26 + 'a') + res;
        a /= 26;
        //cout << a << endl;
    }
    return res;
}

int main()
{
//    string test = "";
//    for (int i = 0; i < 1000; i++)
//    {
//        test += (char)(rand() % 26 + 'a');
//    }
//    cout << test << endl;
    //cout << getStr(35, 3) << endl;
    int t;
    cin >> t;
    //t = 0;
    for (int z = 0; z < t; z++)
    {
        int n;
        cin >> n;
        string word;
        cin >> word;

        for (int i = 0; i < n; i++)
        {
            suffix[i] = word.substr(i);
        }

        sort(suffix, suffix + n);

        int curIndex = 0;
        int curLength = 1;
        int prevNum = -1;
        int temp = 26;

        while (true)
        {
            if (suffix[curIndex].length() < curLength)
            {
                curIndex++;
                if (curIndex == n)
                {
                    curIndex = 0;
                    curLength++;
                    prevNum = -1;
                }
                continue;
            }
            int curNum = getNum(suffix[curIndex].substr(0, curLength));
            if (curNum - prevNum > 1)
            {
                cout << getStr(prevNum + 1, curLength) << endl;
                break;
            }
            else
            {
                prevNum = curNum;
                curIndex++;
                if (curIndex == n)
                {
                    if (prevNum != temp - 1)
                    {
                        cout << getStr(prevNum + 1, curLength) << endl;
                        break;
                    }
                    temp *= 26;
                    curIndex = 0;
                    curLength++;
                    prevNum = -1;
                }
            }
        }

//        for (int i = 0; i < n; i++)
//        {
//            cout << getNum(suffix[i].substr(0, 1)) << endl;
//        }

//        for (int i = 0; i < n; i++)
//        {
//            cout << suffix[i] << endl;
//        }
    }
}
