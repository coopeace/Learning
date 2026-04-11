#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory {
public:
  void get_data(){
    cout << "Enter Name:";
    cin >> name;
    cout << "Enter code:";
    cin >> code;
    cout << "Enter cost:";
    cin >> cost;
  }

  void put_data(){
    cout << setw(10) << name
      << setw(10) << code 
      << setprecision(2) << setw(10) << cost;
  }
  
private:
    string name;
    int code;
    float cost;
};


int main () {
  Inventory item;
  fstream iofile;

  iofile.open("STOCK.DAT",ios::ate|ios::in | ios::out | ios::binary);
  iofile.seekg(0,ios::beg);

  cout << "CURRENT CONTENTS OF STOCK" << endl;

  while (iofile.read((char *)&item, sizeof(item))) {
    item.put_data();
  }
  iofile.clear();
  
  //ADD AN item
  item.get_data();

  return 0;
}
