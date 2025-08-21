#include <iostream>
#include <ctime>

int main(){
  srand(time(NULL));
  char anyr='y';

  while(anyr != 'q'){
  int num = (rand()%6+1);
  std::cout << num << '\n';
  std::cout << "Press q for quit:";
  std::cin >> anyr;
  }
  return 0;
}
