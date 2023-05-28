#include <iostream>
#include <bitset>
#include <sstream>
#include <set>
using namespace std;
#define MAXN 8200

int bytes[MAXN];
bitset<256> keys[MAXN];
bitset<256> cand[MAXN];

int main()
{
    string str;
    cin >> str;
    int n = str.length() / 2;

    for (int i = 0; i < n; i++)
    {
        stringstream ss;
        ss << hex << str[i * 2] << str[i * 2 + 1];
        ss >> bytes[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int c = 'a'; c <= 'z'; c++)
        {
            keys[i][bytes[i] ^ c] = 1;
            //cout << (bytes[i] ^ c) << endl;
        }
        for (int c = 'A'; c <= 'Z'; c++)
        {
            keys[i][bytes[i] ^ c] = 1;
            //cout << (bytes[i] ^ c) << endl;
        }
        for (int c = '0'; c <= '9'; c++)
        {
            keys[i][bytes[i] ^ c] = 1;
            //cout << (bytes[i] ^ c) << endl;
        }
        //cout << bytes[i] << endl;
    }

    for (int i = 1; ; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cand[j].set();
        }
        for (int j = 0; j < n; j++)
        {
            // for (int k = 0; k < 256; k++)
            // {
            //     if (keys[j][k])
            //     {
            //         cout << cand[j] << " " << k << endl;
            //     }
            // }
            cand[j % i] &= keys[j];
        }
        
        set<string> cur, next;
        cur.insert("");
        for (int j = 0; j < i; j++)
        {
            //cout << j << endl;
            for (int k = 0 ; k < 256; k++)
            {
                if (cand[j][k])
                {
                    stringstream ss;
                    ss << hex << k;
                    //cout << j << ", " << k << endl;
                    string add = ss.str();
                    if (add.length() == 1)
                        add = "0" + add;
                    for (string s : cur)
                    {

                        next.insert(s + add);
                    }
                    //cout << hex << j << endl;
                }
            }
            swap(cur, next);
            next.clear();
        }
        if (!cur.empty())
        {
            for (string s : cur)
            {
                cout << "0x" << s << endl;
            }
            break;
        }
    }
}

//93feee9fcdedeacad8db
//382318036960
//