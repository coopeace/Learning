// There could only be virtual Destructor ,no virtual constructor 
class A {
public:
  virtual ~A(){ /*Base Class Construtor*/ }
};

class B: public A{
public:
  ~B(){ /*Derived Class Destructor*/ }
};

 int main(){
  A *ptr = new B();
  delete ptr;// This will invoke Derived class Destructor if it was not virtual it will only invoke base class Destructor(memory leak)
  return 0;
}
