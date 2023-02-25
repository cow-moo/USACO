#include <iostream>
#include <vector>
using namespace std;

string p;

bool is_palindrome(int start, int length, vector<int> &m)
{
    return length == m[2 * start + length - 1];
//    for (int i = 0; i < length / 2; i++)
//    {
//        if (p[start + i] != p[start + length - 1 - i])
//            return false;
//    }
//    return true;
}

//bool pal[100050];

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main()
{
    int t;
    cin >> t;

    for (int z = 1; z <= t; z++)
    {
        int n;
        //string p;
        cin >> n >> p;

        vector<int> temp = manacher(p);
//        for (auto a : temp)
//        {
//            cout << a << endl;
//        }
        for (int i = 0; i < 2 * n - 1; i++)
        {
            temp[i]--;
        }

        for (int i = 1; i <= n / 2 + 1; i++)
        {
            if (is_palindrome(0, i, temp) && is_palindrome(i, n - i, temp))
            {
                cout << "Case #" << z << ": " << p.substr(0, i) << endl;
                break;
            }
            if (i == n / 2 + 1)
            {
                cout << "Case #" << z << ": " << p << endl;
            }
        }
    }
}
