#include <iostream>
#include <vector>

using namespace std;

void vectorPrint(const vector<int> &v){
  for (const auto e:v)
    cout << e << " ";
  cout << endl;
}

int main () {
  vector<int> v ;
  v.push_back(23);
  v.push_back(46);
  v.emplace_back(67);//dynamically increase size of v and faster than push_back

  vectorPrint(v);

  vector<pair<int,int>> p;
  p.push_back({2,3});
  p.emplace_back(91,78);
  for (const auto e:p){
      cout << e.first << " " << e.second;
      cout << endl;
  }

  vector<int> z(5,10);
  // vector<int> z(5);
  vectorPrint(z);

  vector<int> z2(v);
  vectorPrint(z2);

  // Iterator

  vector<int>::iterator it = v.begin();
  cout << "iterator at begin:" << *(it) << endl;

  it += 2;
  cout << "iterator at begin+2:" << *(it) << endl;

  // Erase

  vector<int> v2 = {10,23,45,34,90};

  // v2.erase(v2.begin()+1);
  v2.erase(v2.begin()+1,v2.begin()+4); //till

  vectorPrint(v2);
  // Insert 

  v2.insert(v2.begin()+1,2,83);
  vectorPrint(v2);
  v.insert(v.begin()+2,53);
  vectorPrint(v);
  vector<int> copy = {92,102,18};

  v2.insert(v2.begin(),copy.begin(),copy.end());
  vectorPrint(v2);
  
  cout << "v :" << endl ;
  vectorPrint(v) ;
  cout << "v2 :" << endl ;
  vectorPrint(v2) ;

  cout << "After Swap" << endl;
  v.swap(v2);

  cout << "v :" << endl ;
  vectorPrint(v) ;
  cout << "v2 :" << endl ;
  vectorPrint(v2) ;

  v.clear();
  cout << "Elements of v" << endl;
  vectorPrint(v);

  cout << "is v empty?" << v.empty() << endl;
  cout << "is v2 empty?" << v2.empty() << endl;

  cout << "Size of v2 : " << v2.size() << endl;
  return 0;
}
