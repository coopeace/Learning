
/*

****
*  *
*  *
****

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  // Upper
  for (i=0;i<2;i++){
    for (j=0;j<2-i;j++)
      cout << "*";
    for (j=0;j<2*i;j++)
      cout << " ";
    for (j=0;j<2-i;j++)
      cout << "*";
    cout << endl;
  }

  // Lower
  for (i=0;i<2;i++){
    for (j=0;j<=i;j++)
      cout << "*";
    for (j=0;j<2*(2-i-1);j++)
      cout << " ";
    for (j=0;j<=i;j++)
      cout << "*";
    cout << endl;
  }

  return 0;
}
