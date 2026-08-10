
/*

* * * * * 
* * * * 
* * * 
* * 
* 

*/
#include <iostream>

using namespace std;

int main () {
  for (int i=5;i>0;i--){
    for (int j=5;j>5-i;j--){
      cout << "* ";
    }
    cout << "\n";
  }
  return 0;
}
