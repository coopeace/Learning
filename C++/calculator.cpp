#include <cstdlib>
#include<iostream>

int main(){
  double a,b,c;
  int key,f=0;
  std::cout << "Welcome to the calsmart--->\n";
  while(1){
    if(f==0){
      std::cout << "Enter 1st Num:";
      std::cin >> a;
      f=1;
    }
    std::cout << "Enter 2nd Num:";
    std::cin >> b;
    std::cout << "<---Arthmetic Operations--->\n";
    std::cout << "1.Additon-(1)\n2.Substraction(2)\n3.Multiplication-(3)\n4.Divide-(4)\n";
    std::cout << "Your chhoice:";
    std::cin >> key;
    switch(key){
      case 1:
        c=a+b;
        std::cout << a << "+" << b << "=" << c << '\n';//printout a+b=c
        a=c;
        break;
      case 2:
        c=a-b;
        std::cout << a << "-" << b  << "=" << c << '\n';//printout a-b=c
        a=c;
        break;
      case 3:
        c=a*b;
        std::cout << a << "*" << b << "="  << c << '\n';//printout a*b=c
        a=c;
        break;
      case 4:
        c=a/b;
        std::cout << a << "/" << b << "="  << c << '\n';//printout a/b=c
        c=a;
        break;
      default:
        std::cout << "Invalid chhoice\n";
        std::cout << "Try Again\n";
    }
    char ques;
    std::cout << "Do you want to continue(y/n):";
    std::cin >> ques;
    if(ques == 'n' || ques =='N'){
      return 0;
  }
    std::cout << "1st Num:" << a <<'\n';
}
return 0;
}
