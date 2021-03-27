#include <iostream>
#include <string>
using namespace std;

int main() {
  int *array = new int[10];
  int *ptr = array;
  for (int i=0; i < 10; i++) {
    *ptr = i;
    ptr++;
  }

  cout << ptr << endl;
  cout << array << endl;
}
