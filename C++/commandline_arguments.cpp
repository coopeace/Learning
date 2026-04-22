#include <print>
#include <fstream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
  if (argc < 4 ) {
    println(stderr,"Usage : {} <limit_of_range> <odd> <even>",argv[0]);
    return 1;
  }
  int n = stoi(argv[1]);

  ofstream odd(argv[2]);
  ofstream even(argv[3]);
  if (!odd || !even) {
        println(stderr, "Error opening output files!");
        return 1;
    }
  for ( int i = 1 ; i <= n && n > 0 ; i++ ) {
    if (i%2==0) {
      println(stderr,"{} is an even number.",i);
      println(even,"{}",i);
    }
    else {
      println(stderr,"{} is an odd number.",i);
      println(odd,"{}",i);
    }
  }

  odd.close();
  even.close();
  return 0;
}
