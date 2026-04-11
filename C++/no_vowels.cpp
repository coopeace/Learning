#include<iostream>
// #include <string>

using namespace std;

// use of function
// bool isvowel(char c){
//   return string("AEIOUaeiou").find(c)!=string::npos;
// }


int main(){
  clog << "Program Started" << endl;
  char c;
  while (cin.get(c)) {
    if (c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ) {
      continue;
    }
    cout << c;
    //if (!isVowel(c)) cout << c;
  }
  return 0;
}
