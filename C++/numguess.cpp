#include <iostream>
#include <ctime>

int main(){
  int num,guess,tries=0;

  srand(time(0));
  num = (rand()%100)+1;
  

  std::cout << "-------Number Guessing Game-------\n";

  do {
  std::cout << "Enter a guess between(1-100):";
  std::cin >> guess;
  tries++;
  if(guess>num){
    std::cout << "Too High!\n";
  }
  else if(guess < num){
    std::cout << "Too low\n";
  }
  else{
    std::cout << guess << " is correct\n";
    std::cout << "Number of tries = " << tries;
  }
  }while (guess!=num);
}
