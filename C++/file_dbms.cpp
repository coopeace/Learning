// Accessing Random Data for Displaying,Updating,Inserting,Deleting inside of a I/O 

#include <ios>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Inventory{
  char name[20];
  int code;
  float cost;
  
  public:
  void get();
  void show();
};

int main(){
  Inventory item;
  fstream file;
  file.open("STOCK.DAT",ios::in|ios::out|ios::ate|ios::binary);

  if (!file.is_open()) {
    clog << "ERROR!!  :  FILE COULD NOT BE OPENED" << endl;
    clog << "CREATING STOCK.DAT" << endl;
    file.open("STOCK.DAT", ios::in | ios::out | ios::binary | ios::trunc);
  }

  file.seekg(0,ios::beg);
  //Reading I/O File
  cout << setw(33) << "CURRENT CONTENTS IN STOCK" << endl;

  while (file.read((char *) &item, sizeof(item))) {
    item.show();
  }
  file.clear();
  file.seekg(0,ios::end);

  //Add one more Item
  cout << " Add an item >>" << endl;
  item.get();
  file.write((char *) &item, sizeof(item));

  //Display the appended file
  file.seekg(0,ios::beg);

  cout << setw(22) << "CONTENTS OF APPENDED FILE" << endl; 

  while (file.read((char *) &item, sizeof(item))) {
    item.show();
  }

  file.clear();

  int end = file.tellg();
  int n = end/sizeof(item);

  cout << "Number of objects: " << n << endl;
  cout << "Number of bytes: " << end << endl;

  // Modify The Details Of An Item
  
  cout << "Enter Object Number To Be Updated" << endl;
  int object; cin >> object;

  int location = (object-1)*sizeof(item);

  if (file.eof())
    file.clear();

  file.seekp(location);

  cout << "Enter new values of the object :" << endl;
  item.get();

  file.write((char *) &item,sizeof(item));
  file.flush();

  //Show Updated File 

  file.seekg(0,ios::beg);
  cout << "CONTENTS OF UPDATED FILE" << endl;

  while (file.read((char *) &item,sizeof(item))) {
    item.show();
  }

  file.close();

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
       << fixed << setprecision(2) << setw(10) << cost
       << endl;

}
