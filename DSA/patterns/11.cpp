
/*

*
**
***
****
*****
****
***
**
*

*/
#include <iostream>

using namespace std;

int main () {
  int i,j,stars;

  for (i=1;i<=2*5-1;i++){
    stars = i;
    if (i > 5)
      stars = 2*5 - i;
    for (j=0;j<stars;j++){
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}
