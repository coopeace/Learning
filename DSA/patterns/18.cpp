
/*

E 
D E
C D E
B C D E 
A B C D E

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;

  for (i=0;i<5;i++){
    for (j=69-i;j<=69;j++){
      cout << char(j) << " ";
    }
    cout << endl;
  }

  return 0;
}
