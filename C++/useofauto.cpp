#include <initializer_list>
#include<iostream>

using namespace std;

// METHOD - 1
/*template <typename T>
void printArray(const &T arr){
  for ( auto x : arr)
    cout << x << endl;
}
*/

// METHOD 2
auto printArray(initializer_list<int> arr){
  for ( auto x : arr)
    cout << x << endl;
}

int main(){
  auto array = {1,2,3,4};
  printArray(array);
  return 0;
}
