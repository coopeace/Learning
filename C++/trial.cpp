#include<iostream>

int main(){
  std::string cardnumber;
  std::cout << "Enter a card number:";
  std::cin >> cardnumber;
  int i = cardnumber.size()-2;
  std::cout << cardnumber[i] << '\n';
  return 0;
}
