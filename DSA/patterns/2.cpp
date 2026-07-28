#include <iostream>

using namespace std;

int main () {
  for (int i = 0;i<4;i++){
    for (int j=i;j<4;j++){
      cout << "*";
    }
    cout << "\n";
  }
  return 0;
}
