#include <iostream>
using namespace std;

class Y;

class X{
  public:
    int fun1(Y &objY);
    int fun2(Y &objY);
};

class Y{
  private:
    int value;
  public:
    friend class X;
    Y(int x) : value(x) {}
};

int X::fun1(Y &objY) { // Pass a Y object to the function
    // Accessing private 'value' of Y because fun1 is a friend!
    cout << "X is accessing Y's private value: " << objY.value << endl;
    return 0;
}

int X::fun2(Y &objY) { // Pass a Y object to the function
    objY.value = 90;
    cout << "X is accessing Y's private value: " << objY.value << endl;
    return 0;
}

int main(){
  X Shishir;
  Y Keshav(89);
  Shishir.fun1(Keshav);
  Shishir.fun2(Keshav);
  return 0;
}

