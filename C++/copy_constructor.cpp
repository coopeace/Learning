#include <iostream>
using namespace std;

class A{
  public:
    int value;
    A() {}
    A(A &x){value = x.value;}
};

int main(){
  A obj_1;
  obj_1.value=45;
  A obj_2 = obj_1;
  cout << obj_2.value << endl;
  return 0;
}

