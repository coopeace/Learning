//Getter and Setter
#include<iostream>

class Channel{
  private:
    int number=0;
  public:
    Channel(int number){
      setNumber(number);
    }
    int getNumber(){
      return number;
    }
    void setNumber(int number){
      this->number=number;
    }
};

int main(){
  Channel channel(56);
  std::cout << channel.getNumber() << '\n';

  return 0;
}
