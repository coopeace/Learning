
/*

A
BB
CCC
DDDD
EEEEE

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  for (i=65;i<65+5;i++){
    for (j=65;j<=i;j++){
      cout << char(i);
    }
    cout << endl;
  }

  return 0;
}
