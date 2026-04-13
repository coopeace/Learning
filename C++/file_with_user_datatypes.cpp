// This program is an example of reading user defined data types from a i/o

#include <ios>
#include <string>
#include <print>
#include <fstream>

using namespace std;

class emp{
  public:
    emp() {}
    emp(string name,int n) : ecode(n),m_name(name) {}
    void show() { println("Ecode:{}   Name:{}",ecode,m_name); }
  private:
    int ecode;
    string m_name;
};

int main(){

  emp e[] = {{"Amit",1},{"Joy",2},{"Rahul",3},{"Vikas",4}};
  
  fstream file;
  file.open("Employee.txt",ios::in|ios::out|ios::trunc|ios::binary);
  if (!file.is_open()) {
    println("Error : File Could not be opened");
      return 1;
  }

  for ( emp i : e){
    file.write((char *) &i,sizeof(i));
  }

  file.seekg(0,ios::end);

  int end = file.tellg();

  println("Number of objects:{}",end/sizeof(emp));

  return 0;
}
