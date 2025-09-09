#include<iostream>

int main(){
  double a=0,b;
  int choice;
  while(1){
  std::cout << "************************\n";
  std::cout << "  Arthmetic Opertions\n";
  std::cout << "************************\n";
  std::cout << "1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n5.Quit\n";
  std::cout << "************************\n";
  std::cout << "ANS:" << a << '\n';
  std::cout << "Enter your choice(1-5):";
  std::cin >> choice;
  if(choice == 5){
    return 0;
  }
  std::cout << "Enter your number:";
  std::cin >> b;
  switch(choice){
    case '+':
      a+=b;
      break;
    case '-':
      a-=b;
      break;
    case '*':
      a*=b;
      break;
    case '/':
      a/=b;
      break;
    default:
      std::cout << "Invalid Choice!!!\n";
  }
  }
  return 0;
}
