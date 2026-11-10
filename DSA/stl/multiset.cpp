#include <iostream>
#include <set>

using namespace std;

/*
 * Sorted 
 * Functions of vector are also here (efficient)
 * insert,begin,end,rbegin,rend,size,empty,swap
 * Time Complexity = O(log n)
 */

int main (){
  multiset<int> st;
  st.insert(2);
  st.insert(5);
  st.emplace(4);
  st.insert(3);
  st.insert(4);

  // auto it = st.find(3);// iterator

  for (auto e:st)
    cout << e << " ";
  cout << endl;

  // st.erase(4);// erases' all 4 in a set
  // st.erase(st.find(4));// erases' first occurence of 4.
  // st.erase(st.find(4),st.find(4)+2);// start to end

  for (auto e:st)
    cout << e << " ";
  cout << endl;

  int count = st.count(4);
  cout << "Number of 4 in set: " << count << endl;

  return 0;
}
