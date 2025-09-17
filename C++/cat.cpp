#include<iostream>
#include <string>

class Cat{
  public:
    std::string breed;
    std::string color;
    int age;

    void walk(){
      std::cout << "It is walking.\n";
    }
    void sleep(){
      std::cout << "It is sleeping.\n";
    }
    void licking(){
      std::cout << "It is sitting and licking itself.\n";
    }
    void meow(){
      std::cout << "Meowww.\n";
    }
};

int main(){
  Cat cat1;
  cat1.breed= "British Shorthair";
  cat1.color= "Grey";
  cat1.age = 8;

  std::cout << cat1.breed << '\n';
  std::cout << cat1.color << '\n';
  std::cout << cat1.age << '\n';
  
  cat1.walk();
  cat1.meow();
  cat1.licking();
  cat1.meow();
  cat1.sleep();

  return 0;
}
