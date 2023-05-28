#include <iostream>
using namespace std;

int FUNNY_MEMORY[10];
int main() {
  FUNNY_MEMORY[11] = 0xdeadbeaf;
}