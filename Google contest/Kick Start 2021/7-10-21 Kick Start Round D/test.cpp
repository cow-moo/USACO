#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> test;
    test.insert(10);
    set<int>::iterator bruh = test.begin();
    (*bruh) = 10;

    cout << (*bruh) << endl;
}
