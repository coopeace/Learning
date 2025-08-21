#include<iostream>

int print_Happy_birthday(int x){
  std::cout << "Happy birthday to you\n";
  if(x==1){
    return 0;
  }
  return x + print_Happy_birthday(x-1);
}

int main(){
  print_Happy_birthday(10);
  return 0;
}
