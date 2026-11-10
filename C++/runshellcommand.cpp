#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdio>

using namespace std;

void shell_grep_output(const string &input,string &result){
  string command = "ls -l | grep " + input;
  char buffer[256];
  FILE *pipe = popen(command.c_str(), "r");
  if (!pipe)
    throw runtime_error("popen() failed!");
  while (fgets(buffer,sizeof(buffer),pipe)!=nullptr)
    result += buffer;
  pclose(pipe);
}

int main(){
  string input,result;
  cout << "Enter the pattern:" ;
  cin >> input;
  try {
  cout <<  result << endl;
    shell_grep_output(input,result);
    cout <<  result << endl;
  } catch (const exception &e){
    cerr << "Error :" << e.what() << endl;
  }
  return 0;
}
