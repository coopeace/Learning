#include <iostream>
#include <deque>

using namespace std;

// Same as list

void dequePrint(deque<int>&dq){
  for (auto e : dq)
    cout << e << " ";
  cout << endl;
}

int main () {
  deque<int> dq = {82,19};

  dequePrint(dq);

  cout << "Push Back and Emplace Back\n";

  dq.push_back(23);
  dq.emplace_back(34);

  dequePrint(dq);

  cout << "Push Front and Emplace Front\n";

  dq.push_front(101);
  dq.emplace_front(92);
  
  dequePrint(dq);

  dq.pop_back();
  dq.pop_front();

  dequePrint(dq);

  // Other Functions
  // begin,end,rbegin,rend,clear,insert,size,swap
  return 0;
}
