#include<iostream>

class Animal{
  public:
    bool isalive = true;
    bool canrun = true;
    int paws=4;
};

class Cat : public Animal{
  public:
    void meow(){
      std::cout << "Cat sound : Meoowwww.\n";
    }
    void purr(){
      std::cout << "Cat is puurrrrring.\n";
    }
};

class Dog : public Animal{
  public:
    void bark(){
      std::cout << "Dog sound : Wooof\n";
    }
    void guard(){
      std::cout << "Dog is Guarding it's Territory.\n";
    }
};

int main(){
  Dog dog;
  Cat cat;

  std::cout << (dog.isalive ? "Dog is alive." : "Dog is not alive.") << '\n';
  std::cout << (cat.isalive ? "Cat is alive." : "Cat is not alive.") << '\n';
  std::cout << (dog.canrun ? "Dog can run." : "Dog cannot run.") << '\n';
  std::cout << (cat.paws==4 ? "Cat has four paws." : "Cat doesn't have four paws.") << '\n';

  cat.meow();
  cat.purr();
  dog.bark();
  dog.guard();
  return 0;
}
