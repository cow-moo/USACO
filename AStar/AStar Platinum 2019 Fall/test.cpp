#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int test1[3] = {34, 3, 2};
    int test2[3] = {34, 3, 0};

    cout << lexicographical_compare(test1, test1 + 3, test2, test2 + 3) << endl;
}
