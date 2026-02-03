#include <iostream>
#include <string>

using namespace std;

bool isvowel(char ch){
  string vowels="AaEeIiOoUu";
  return (vowels.find(ch)!=string::npos) ? true : false;
}

int main(){
  char choice;
  char x;
  do{
    cout << "Enter a char:";
    cin >> x;
    isvowel(x);
    cout << "Press q for exit:";
    cin >> choice;
  }while(choice!='q');
  return 0;
}
