
/*

 1             1
 1 2         2 1
 1 2 3     3 2 1
 1 2 3 4 4 3 2 1

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  for (i=1;i<=4;i++){
    for (j=1;j<=i;j++){
      cout << j ;
    }

    for (j=1;j<=2*(4-i);j++){
      cout << " ";
    }

    for (j=i;j<=i && j > 0;j--){
      cout << j;
    }
    cout << "\n";
  }

  return 0;
}
