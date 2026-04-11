#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
  float heights[] = {167.23,150.23,192.12,182.89};

  fstream file;
  file.open("Heights",ios::in | ios::out | ios::trunc);

  if (!file.is_open()) {
    cerr << "File could not be opened." << endl;
  }

  file.write((char*)&heights,sizeof(heights));

  file.flush();//no need
  file.clear();//no need

  file.seekg(0);//file.seekg(0, ios::beg); better

  for ( auto &height : heights) {
    clog << "Removing Height in the array" << endl << height << endl;
    height = 0;
    clog << "After Removing:" << height << endl;
  }

  file.read((char*)&heights,sizeof(heights));

  for (auto &height : heights) { 
    clog << "Entering Height in the array" << endl << height << endl;
    cout.setf(ios::showpoint);
    cout << fixed << setw(10) << setprecision(2) << height;
  }
  // file << heights;
  // for ( auto height : heights ){
  //   cout << setw(10) << height;
  // }

  file.close();
  
  return 0;
}
