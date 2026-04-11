// Learning the use of put and get
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
  string str;

  cout << "Enter a string>>" << endl;
  getline(cin >> ws,str);

  fstream file;
  clog << "Storing string in file" << endl;

  file.open("string.txt",ios::in | ios::out | ios::trunc);
  
  if (!file.is_open()) { 
    cerr << "file couldn't be opened" << endl;
    return 1;
  }
  for (char c : str) { file.put(c);}

  file.flush();// ensure write is done (optional but good)
  file.clear();// EOF or failbit--flags was set earlier, reading may fail
  file.seekg(0);

  clog << "Reading the file" << endl;

  char c;
  while(file.get(c)) { //read whole file
    cout << c;
  }

  //  Alternative
  //file << str;
  //file.seekg(0);
  //cout << file.rdbuf();

  file.close();

  return 0;
}
