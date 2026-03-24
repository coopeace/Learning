#include <iostream>

int main () {
  char c;
  std::cout << "->";
  do {
   std::cin.get(c);// returns with whitspace(space,tab)
   // std::cin >> c;// returns without whitspace and programme is not closed when '\n'
   std::cout << c;
  } while ( c != '\n');
  return 0;
}
