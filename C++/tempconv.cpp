#include<iostream>

int main(){
  double temp;
  char unit;
   std::cout << "----------Temp Conversion-------------\n";
   std::cout << "F:Farenheit\nC:Celsius\n";
   std::cout << "Choose a unit you want to convert:";
   std::cin >> unit;

   if(unit == 'f' || unit == 'F'){
     std::cout << "Enter a temp in Celsius:";
     std::cin >> temp;

     temp = (1.8*temp)+32.0;
     std::cout << "Temp is: " << temp << "F\n";
   }
   else if(unit == 'c' || unit == 'C'){
     std::cout << "Enter a temp in Farenheit:";
     std::cin >> temp;

     temp = (temp-32.0)/1.8;
     std::cout << "Temp is: " << temp << "C\n";
   }
   else{
     std::cout << "Please enter in C or F\n";
   }
  return 0;
}
