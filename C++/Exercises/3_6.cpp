#include <iostream>

using namespace std;

class player{
  public:
    int runs;
    int innings;
    int not_out;
    float average;
  void calculate_average(){
    average = (float)runs/(innings-not_out);
  }
  player(int x, int y, int z) : runs(x),innings(y),not_out(z) {}

  void dislpay_stats(){
    cout << "Runs: " << runs << endl;
    cout << "innings: " << innings << endl;
    cout << "not_out: " << not_out << endl;
    cout << "average " << average << endl;
  }
};


int main(){
  player Sachin(8430, 230, 18);
  player Saurav(4200,130,9);
  player Rahul(3350,105,11);
  
  Sachin.calculate_average();
  Saurav.calculate_average();
  Rahul.calculate_average();

  cout << "Player stats-->" << endl;
  cout << "\nSachin-->" << endl;
  Sachin.dislpay_stats();

  cout << "\nSaurav-->" << endl;
  Saurav.dislpay_stats();

  cout << "\nRahul-->" << endl;
  Rahul.dislpay_stats();
  
  return 0;
}
