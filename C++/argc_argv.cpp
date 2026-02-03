#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc,char * argv[]){
  if (argc < 4) {
        cout << "Usage: " << argv[0] << " <num1> <anything> <num2>" << endl;
        return 1; // Exit with error
  }
  int a = atoi(argv[1]);
  int b = atoi(argv[3]);
  cout << argv[1] << " + " << argv[3] << " = "<< a+b << endl;
  return 0;
}
