
/*

 A
 AB
 ABC
 ABCD
 ABCDE

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  for (i=65;i<65+5;i++){
    for (j=65;j<=i;j++){
      cout << char(j);
    }
    cout << endl;
  }

  return 0;
}
