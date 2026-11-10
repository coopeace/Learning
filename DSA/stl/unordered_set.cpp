#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * Unique
 * Functions of vector are also here (efficient)
 * insert,begin,end,rbegin,rend,size,empty,swap
 * upperbound and lowerbound Functions do not exist 
 * Time Complexity = O(1)
 * Worst TC = O(N) Once in a blue moon
 */

int main (){
  unordered_set<int> st;
  st.insert(2);
  st.insert(5);
  st.emplace(4);
  st.insert(3);
  st.insert(4);

  for (auto e:st)
    cout << e << " ";
  cout << endl;

  return 0;
}
