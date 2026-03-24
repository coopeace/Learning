#include <iostream>
#include <ostream>
#include <iomanip>

using namespace std;

ostream &show(ostream & output)
{
  output.setf(ios::showpoint);
  output.setf(ios::showpos);
  output << setw(10);
  return output;
}

ostream &noshow(ostream &output)
{
  output.unsetf(ios::showpoint);
  output.unsetf(ios::showpos);
  return output;
}

ostream &unit(ostream &output)
{ 
  output << " inches";
  return output;
}

ostream &currency(ostream &output)
{
  output << " Rs";
  return output;
}

int main () {
  cout << 36 << currency << endl;
  cout << show << 2345 << endl;
  cout << noshow << 103 << unit << endl; 
  return 0;
}
