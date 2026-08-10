
/*

    *    
   ***   
  *****  
 ******* 
*********

*/
#include <iostream>

using namespace std;

int main () {
  int i,j;
  for (i=0;i<5;i++){
    for (j=0;j<5-i-1;j++){
      cout << " ";
    }

    for (j=0;j<2*i+1;j++){
      cout << "*";
    }

    for (j=0;j<5-i-1;j++){
      cout << " ";
    }
    cout << "\n";
  }
  return 0;
}
