#include <iostream>
#include <iomanip>

using namespace std;

int main () {
  cout << setw(10) << 12345 << endl;
  cout << setw(12) << setiosflags(ios::left) << 56789;
  return 0;
}
