
/*

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1

*/
#include <iostream>

using namespace std;

int main () {
  int i,j,stars;

  for (i=0;i<5;i++){
    stars = (i%2==0) ? 1 : 0;
    for (j=0;j<=i;j++){
      cout << stars << " ";
      stars = 1 - stars;
    }
    cout << "\n";
  }

  return 0;
}
