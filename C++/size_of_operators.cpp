#include<iostream>
#include <string>

int main () {
  int x;
  long a;
  long long b;
  float y;
  double m;
  std::string name;
  char name2[20];
  std::cout << "Size of int:"<<sizeof(x) << '\n';
  std::cout << "Size of long:"<<sizeof(a) << '\n';
  std::cout << "Size of long long:"<<sizeof(b) << '\n';
  std::cout << "Size of float:"<<sizeof(y) << '\n';
  std::cout << "Size of double:"<<sizeof(m) << '\n';
  std::cout << "Size of string:"<<sizeof(name)<< '\n';
  std::cout << "Size of string manually:"<<sizeof(name2)<< '\n';
  return 0;
}
