#include <iostream>
#include <set>

using namespace std;

/*
 * Sorted and Unique
 * Functions of vector are also here (efficient)
 * insert,begin,end,rbegin,rend,size,empty,swap
 * Time Complexity = O(log n)
 */

int main (){
  set<int> st;
  st.insert(2);
  st.insert(5);
  st.emplace(4);
  st.insert(3);
  st.insert(4);

  // auto it = st.find(3);// iterator

  for (auto e:st)
    cout << e << " ";
  cout << endl;

  // st.erase(4);
  st.erase(st.find(3),st.find(5));

  for (auto e:st)
    cout << e << " ";
  cout << endl;

  int count = st.count(3);
  cout << (!(count==0) ? "Occurs" : "Occurs Not") << endl;

  return 0;
}
