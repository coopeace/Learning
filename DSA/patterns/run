
/*

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

*/
#include <iostream>

using namespace std;

int main () {
  int i,j,n,left,right,top,bottom;

  cout << "Enter a number:";
  cin >> n;

  for ( i=0;i<2*n-1;i++){
    for ( j=0;j<2*n-1;j++){
      top =i;
      left=j;
      right=2*n-2-j;
      bottom=2*n-2-i;
      cout << (n-min(min(left,bottom),min(right,top))) << " ";
    }

    cout << endl;
  }
  return 0;
}
