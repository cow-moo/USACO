#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<pair<int, int>, int> ratioCount;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

pair<int, int> simplify(pair<int, int> a)
{
    int temp = gcd(a.first, a.second);
    return {a.first / temp, a.second / temp};
}

int main()
{
//    pair<int, int> a = {21, 7};
//    a = simplify(a);
//    cout << a.first << " " << a.second << endl;

    int t;
    cin >> t;

    for (int z = 0; z < t; z++)
    {
        ratioCount.clear();
        int n;
        cin >> n;
        string wood;
        cin >> wood;

        pair<int, int> curRatio = {0, 0};
        for (int i = 0; i < n; i++)
        {
            if (wood[i] == 'D')
                curRatio.first++;
            else
                curRatio.second++;

            pair<int, int> simp = simplify(curRatio);
            cout << ratioCount[simp] + 1 << " ";

            ratioCount[simp]++;
        }
        cout << endl;
    }
}
