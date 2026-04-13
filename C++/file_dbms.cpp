// Accessing Random Data for Displaying,Updating,Inserting,Deleting inside of a I/O 

#include <ios>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Inventory{
  int code;
  float cost;
  string name;
  
  public:
    void get();
    void show();
};

int main(){
  Inventory item;
  fstream file;
  file.open("Stock.dat",ios::in|ios::out|ios::trunc|ios::binary);

  if (!file.is_open()) {
    cerr << "Error!!  :  File Could not be Opened" << endl;
    return 1;
  }

  //Reading I/O File
  cout << setw(33) << "Current Contents in Stock" << endl;

  while (file.read((char *) &item, sizeof(item))) {
    item.show();
  }
  file.flush();
  file.clear();
  file.seekg(0,ios::end);

  //Add one more Item
  cout << "Add an Item" << endl;
  item.get();
  file.write((char *) &item, sizeof(item));

  //Display the appended file
  file.seekg(0,ios::beg);

  cout << setw(22) << "Contents of appended File" << endl; 

  return 0;
}

void Inventory::get(){

  cout << " Enter name: "; cin >> name;
  cout << " Enter code: "; cin >> code;
  cout << " Enter cost: "; cin >> cost;

}

void Inventory::show(){

  cout << setw(10) << name
       << setw(10) << code
       << setprecision(2) << setw(10) << cost
       << endl;

}
