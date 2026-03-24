#include <iostream>

using namespace std;

class A{
  public:
    int a;
    void show() {
      cout << "a: " << a <<endl;
    }
};

class B : public A {
  public:
    int b;
    void show() {
      cout << "a: " << a <<endl;
      cout << "b: " << b << endl;
    }
};

int main(){
  A base;
  B derived;
  A *base_ptr;
  base_ptr = &base;

  cout << "using base class pointer" << endl;
  base_ptr->a = 100;
  base_ptr->show();
  
  cout << "using base class pointer on derived class" << endl;
  base_ptr=&derived;
  base_ptr->a=200;
  base_ptr->show();

  B *derived_ptr;
  derived_ptr = &derived;
  cout << "using derived class pointer" << endl;
  derived_ptr->b = 300;
  derived_ptr->show();

  cout << "using (B* base class ptr)" << endl;
  ((B *)base_ptr)->b=400;
  ((B *)base_ptr)->show();
  return 0;
}
