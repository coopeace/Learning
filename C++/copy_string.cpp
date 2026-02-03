#include <iostream>
#include <cstring>
using namespace std;

class A{
  private:
    int length;
    char *name;
  public:
    A(){
      length = 0;
      name = new char[length + 1];
    }
    A(char *str){
      length = strlen(str);
      name = new char[length + 1];
      strcpy(name, str);
    }
    void display(){
      cout << name << endl;
    }
    void join_str(const A &str_1,const A &str_2){
      length = str_1.length + str_2.length;
      delete name;
      name = new char[length + 1];
      strcpy(name, str_1.name);
      strcat(name, str_2.name);
    }
};

int main(){
  char *name="Shishir";
  A name1(name),name2("Dev"),s1;
  name1.display();
  name2.display();
  s1.join_str(name1,name2);
  s1.display();
  return 0;
}

