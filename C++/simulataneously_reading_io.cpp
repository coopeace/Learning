#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main () {
  string country,capital;

  //Read Stream
  ifstream input1,input2;
  input1.open("country_names.txt");
  input2.open("capital_name.txt");

  if (!input1 || !input2 ) {
    cerr << "Files did not open." << endl;
    return 1;
  }

  while (getline(input1,country) && getline(input2,capital)) {

    cout << country << " -> " << capital << endl;

  }

  input1.close();
  input2.close();

  clog << "Finished Reading Files.." << endl;

  return 0;
}
