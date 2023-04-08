#include <iostream>
#include <vector>
using namespace std;

vector<int> function()
{
    cout << "a";
    vector<int> res;
    res.push_back(3);
    res.push_back(3);
    res.push_back(3);
    res.push_back(3);
    res.push_back(3);
    return res;
}

int main()
{
    for (int x : function())
    {
        cout << x << endl;
    }
}