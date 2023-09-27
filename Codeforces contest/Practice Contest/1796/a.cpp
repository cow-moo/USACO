#include <iostream>
using namespace std;

int main()
{
    string seq = "";
    for (int i = 1; i <= 90; i++)
    {
        if (i % 3 == 0)
            seq += 'F';
        if (i % 5 == 0)
            seq += 'B';
    }
    //cout << seq << endl;

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        string s;
        cin >> k >> s;

        cout << (seq.find(s) != string::npos ? "YES" : "NO") << endl; 
        //cout << (possible.count(s) ? "YES" : "NO") << endl;
    }
}
//BB not possible
//F
//1 4