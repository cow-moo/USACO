#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

string removeLeadingZeros(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != '0' || i == a.length() - 1)
        {
            return a.substr(i);
        }
    }
    return a;
}

string add(string a, string b)
{

    string res = "";
    int sum = 0;
    for (int i = 0; i < max(a.length(), b.length()); i++)
    {
        if (i < a.length())
            sum += a[a.length() - 1 - i] - '0';
        if (i < b.length())
            sum += b[b.length() - 1 - i] - '0';

        res = (char)((sum % 10) + '0') + res;

        sum /= 10;
    }
    if (sum == 1)
        res = "1" + res;

    //cout << "pre: " << res << endl;

    res = removeLeadingZeros(res);

    //cout << a << " add " << b << ": " << res << endl;
    return res;
}

string multiply(string a, string b)
{
    string res = "0";
    for (int j = 0; j < b.length(); j++)
    {
        //multiply a by digit of b
        string curDig = "";
        for (int i = 0; i < j; i++)
        {
            curDig += "0";
        }

        int carry = 0;
        for (int i = 0; i < a.length(); i++)
        {
            carry += (a[a.length() - 1 - i] - '0') * (b[b.length() - 1 - j] - '0');

            curDig = (char)((carry % 10) + '0') + curDig;

            carry /= 10;
        }
        if (carry != 0)
            curDig = (char)((carry % 10) + '0') + curDig;

        res = add(res, curDig);
    }

    res = removeLeadingZeros(res);

    return res;
}

map<pair<string, string>, string> opMap;
string oper(string a, string b)
{
    //return "24";
    if (opMap.count({a, b}) == 0)
    {
        string res = "";
        for (int i = 0; i < 10; i++)
        {
            res += (char)(rand() % 10 + '0');
        }

        res = removeLeadingZeros(res);

        opMap[{a, b}] = res;
        return res;
    }
    else
    {
        return opMap[{a, b}];
    }
}

string simplified(string str)
{
    if (str[0] != '(')
        return str;

    int pDepth = 0;
    char op;
    int opPos;
    for (int i = 1; i < str.length() - 1; i++)
    {
        if (str[i] == '(')
            pDepth++;
        else if (str[i] == ')')
            pDepth--;
        else if (pDepth == 0)
        {
            if (str[i] == '+' || str[i] == '*' || str[i] == '#')
            {
                op = str[i];
                opPos = i;
                break;
            }
        }
    }
    string par1 = str.substr(1, opPos - 1);
    string par2 = str.substr(opPos + 1, str.length() - opPos - 2);

    par1 = simplified(par1);
    par2 = simplified(par2);

    //cout << par1 << ", " << par2 << ", " << op << endl;

    if (op == '+')
    {
        return add(par1, par2);
    }
    else if (op == '*')
    {
        return multiply(par1, par2);
    }
    else if (op == '#')
    {
        return oper(par1, par2);
    }
}

int main()
{
//    string test;
//    while (true)
//    {
//        cin >> test;
//        cout << simplified(test) << endl;
//    }
    //cout << removeLeadingZeros("0000") << endl;
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        cin >> n;
        cout << "Case #" << z << ": ";

        map<string, int> m;
        int classCount = 1;
        for (int i = 0; i < n; i++)
        {
            string inp;
            cin >> inp;
            inp = simplified(inp);
            if (m.count(inp) == 0)
            {
                m[inp] = classCount++;
                cout << m[inp] << " ";
            }
            else
            {
                cout << m[inp] << " ";
            }
            //cout << "s: " << inp << endl;
        }

        cout << endl;
    }

//    for (auto e : opMap)
//    {
//        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
//    }
}

/*
1
3
(1*(1#2))
(0*(1#2))
(1#2)
*/
