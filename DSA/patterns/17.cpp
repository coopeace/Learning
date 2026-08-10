
/*

   A   
  ABA
 ABCBA
ABCDCBA

*/
#include <iostream>

using namespace std;

int main () {
  int i,j,k,count;

  for (i=0;i<4;i++){
    k=65;
    count=0;
    for (j=0;j<=4-1-i;j++){
      cout << " ";
    }
    for (j=0;j<2*i+1;j++){
      cout << char(k);
      // count++;
      k = (++count <= i) ? k+1 : k-1;
    }
    for (j=0;j<=4-i;j++){
      cout << " ";
    }
    cout << endl;
  }

  return 0;
}
