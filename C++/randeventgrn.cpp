#include <iostream>
#include <ctime>

int main(){
  srand(time(0));

  int randnum = (rand() % 3 +1);
  switch (randnum) {
    case 1:
      std::cout << "Do Cleaning";
      break;
    case 2:
      std::cout << "Do Dishes";
      break;
    case 3:
      std::cout << "Cook";
      break;
  }
  return 0;
}
