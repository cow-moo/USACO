#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> test1;
    for (int i = 0; i < 5; i++)
    {
        test1.push_back(i);
    }
    vector<int> test = test1;
    for (int a : test)
    {
        test.push_back(a * 2);
    }
    for (int a : test)
        cout << a << endl;

        cout << endl;
    for (int a : test1)
        cout << a << endl;
}
