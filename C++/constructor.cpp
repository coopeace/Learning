#include <algorithm>
#include<iostream>
#include <string>

class Student{
  public:
    std::string name;
    int age;
    double gpa;

  /*Student(std::string name,int age,double gpa){
   * this->name=name;
   * this->age=age;
   * this->gpa=gpa;
   * }*/

  Student(std::string x,int y,double z){
    name= x;
    age= y;
    gpa= z;
  }
};

int main(){
  Student student1("Spongebob",25,3.2);
  Student student2("Patrick",40,1.5);

  std::cout << student1.name << '\n';
  std::cout << student1.age << '\n';
  std::cout << student1.gpa << '\n';

  std::cout << student2.name << '\n';
  std::cout << student2.age << '\n';
  std::cout << student2.gpa << '\n';
  return 0;
}
