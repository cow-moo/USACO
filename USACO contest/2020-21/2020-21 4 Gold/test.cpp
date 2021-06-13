#include <iostream>
using namespace std;

struct State
{
  int test[3];
  int asdf;
};

int main()
{
    State a = {15, 2, 3, 7};
    cout << a.asdf << endl;
    State b = a;
    b.test[0] = 3;
    cout << a.test[0] << endl;
}
