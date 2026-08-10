#include <iostream>
#include <vector>

using namespace std;

int main () {
  vector<int> v ;
  v.push_back(23);
  v.push_back(46);
  v.emplace_back(67);//dynamically increase size of v and faster than push_back

  for (const auto e:v)
    cout << e << " ";
  cout << endl;

  vector<pair<int,int>> p;
  p.push_back({2,3});
  p.emplace_back(91,78);
  for (const auto e:p){
      cout << e.first << " " << e.second;
      cout << endl;
  }


  vector<int> z(5,10);
  // vector<int> z(5);
  for (auto e:z)
    cout << e << " ";
  cout << endl;

  vector<int> z2(z);
  for (auto e:z2)
    cout << e << " ";
  cout << endl;

  return 0;
}
