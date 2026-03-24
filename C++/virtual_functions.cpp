#include <iostream>

using namespace std;

class Base {
  public:
    void display(){ cout << "Display Base" << endl; }
    virtual void show(){ cout << "Show Base" << endl; }
};

class Derived : public Base {
  public:
    void display(){ cout << "Display Derived" << endl; }
    void show(){ cout << "Show Derived" << endl; }
};

int main(){
  Base base;
  Derived derived;

  Base *base_ptr;
  std::cout << "base_ptr points to Base" << endl;
  base_ptr = &base;
  base_ptr->display();
  base_ptr->show();

  cout << "base_ptr points to Derived" << endl;
  base_ptr = &derived;
  base_ptr->display();
  base_ptr->show();

  return 0;
}
