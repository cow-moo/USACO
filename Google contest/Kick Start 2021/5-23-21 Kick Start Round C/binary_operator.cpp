#include <iostream>
#include <map>
using namespace std;

string add(string a, string b)
{
    //((cout << a << " add " << b << endl;
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
    return res;
}

pair<string, int> simplified(string str)
{
    if (str[0] != '(')
        return {str, 0};

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
    pair<string, int> par1 = {str.substr(1, opPos - 1), 0};
    pair<string, int> par2 = {str.substr(opPos + 1, str.length() - opPos - 2), 0};

    par1 = simplified(par1.first);
    par2 = simplified(par2.first);

    //if 2 const and add/mult
    if (par1.first[0] != '(' && par2.first[0] != '(' && op != '#')
    {
        if (op == '+')
            return {add(par1.first, par2.first), 0};
        else if (op == '*')
            return {multiply(par1.first, par2.first), 0};
    }
    else
    {
        if (op == '#')
        {
            return {"(" + par1.first + '#' + par2.first + ")", par1.first.length() + 1};
        }
        else
        {
            //ensure constant is par1, either {nonc, nonc} or {c, nonc}
            if (par2.first[0] != '(')
                swap(par1, par2);

            if (op == '+')
            {
                if (par1.first == "0")
                    return par2;
                if (par1.first[0] != '(')
                {
                    if (par2.first.)
                }
                else if (par1)
            }
            else if (op == '*')
            {
                if (par1.first == "0")
                    return "0";
                if (par1.first == "1")
                    return par2;
            }


            return "(" + min(par1, par2) + op + max(par1, par2) + ")";
        }
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
            inp = simplified(inp).first;
            if (m.count(inp) == 0)
            {
                m[inp] = classCount++;
                //cout << m[inp] << " ";
            }
            else
            {
                //cout << m[inp] << " ";
            }
            cout << "s: " << inp << endl;
        }

        cout << endl;
    }
}
