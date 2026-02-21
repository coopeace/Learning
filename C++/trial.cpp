#include <iostream>
#include <ostream>

class Numbers{
  private:
    int x;
  public:
    Numbers(int value) : x(value){}  
    void changeNumber(){
      x=35;
    }
    void display(){
      std::cout << "X:" << x << std::endl;
    }
};


int main () {
  Numbers num(8);
  num.display();
  num.changeNumber();
  num.display();
  std::cout << sizeof(num) << std::endl;
  return 0;
}
