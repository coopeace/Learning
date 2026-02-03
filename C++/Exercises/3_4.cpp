#include <iostream>
#include <math.h>
using namespace std;
//V= P*(1 + r)^n
int main(){
  float v,p,r;
  int n;
  std::cout << "Enter Principal Amount,interest rate and time period respectively:" << endl ;
  cin >> p >> r >> n;
  v = p*(pow((1+r),n));
  cout << "Amount : " << v << endl;
  return 0;
}
