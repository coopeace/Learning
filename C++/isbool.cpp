#include <iostream>
#include <string>

using namespace std;

void isvowel(char ch,string &s){
  string vowels="AaEeIiOoUu";
  if(vowels.find(ch)!=string::npos)
    s.insert(0,"An ");
}

int main(){
  char choice;
  string str;
  char ch;
  do{
    cout << "Enter a sentence:";
    getline(cin >> ws,str);
    ch = str.at(0);
    isvowel(ch,str);
    cout << ">>" << str << endl;
    cout << "\nPress q for exit:";
    cin >> choice;
    cout << endl;
  }while(choice!='q');
  return 0;
}
