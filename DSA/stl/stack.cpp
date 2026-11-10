#include <iostream>
#include <stack>

using namespace std;

/* Stack Methods
 * pop,push,top,clear,empty,size,swap
 * Every commands take O(n)
 * LIFO
 */ 

int main () {
  stack<int> st;

  st.push(1);
  st.push(23);
  st.push(99);

  cout << "top : " << st.top() << endl;

  cout << "Popped : " << st.top() << endl;
  st.pop();
  
  cout << "top : " << st.top() << endl;
  
  cout << "is stack empty? " << endl;
  cout << (!(st.empty()==0) ? "Yes" : "No") << endl ; 

  cout << "Size of Stack: " << st.size() << endl;

  return 0;
}

