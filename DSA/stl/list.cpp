#include <iostream>
#include <list>

using namespace std;

// In list we push element to the front
// Use of insert is costly in vectors 

void listPrint(list<int> &l){
  for (auto e : l)
    cout << e << " ";
  cout << endl;
}

int main () {
  list<int> ls = {82,19};

  listPrint(ls);

  cout << "Push Back and Emplace Back\n";

  ls.push_back(23);
  ls.emplace_back(34);

  listPrint(ls);

  cout << "Push Front and Emplace Front\n";

  ls.push_front(101);
  ls.emplace_front(92);
  
  listPrint(ls);

  ls.pop_back();
  ls.pop_front();

  listPrint(ls);

  // Other Functions
  // begin,end,rbegin,rend,clear,insert,size,swap
  return 0;
}
