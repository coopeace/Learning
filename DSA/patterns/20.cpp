
/*

*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  // Upper
  for (i=0;i<5;i++){
    for (j=0;j<=i;j++)
      cout << "*";
    for (j=0;j<2*(5-i-1);j++)
      cout << " ";
    for (j=0;j<=i;j++)
      cout << "*";
    cout << endl;
  }

  // Lower
  for (i=1;i<5;i++){
    for (j=0;j<5-i;j++)
      cout << "*";
    for (j=0;j<2*i;j++)
      cout << " ";
    for (j=0;j<5-i;j++)
      cout << "*";
    cout << endl;
  }
  return 0;
}
