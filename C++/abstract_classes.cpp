#include <iostream>

class Base {
  public:
    virtual void show() = 0;
};

class Derived : public Base {
  public:
    void show(){
      std::cout << "Learning OOPs from Balaguruswamy Book" << std::endl;
    }
};

class Derived_2 : public Base {
  public:
    void show(){
      std::cout << "This is an example of Abstract Classes" << std::endl;
    }
};

int main () {
  Base *ptr = new Derived;
  ptr->show();
  ptr = new Derived_2;
  ptr->show();
  return 0;
}
