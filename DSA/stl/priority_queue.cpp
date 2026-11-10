#include <functional>
#include <iostream>
#include <queue>

/*
 * Biggest Value at the top
 * push,pop - O(log n)
 * top - O(1)
 */

using namespace std;

int main () {
  // MAX Heap
  priority_queue<int> pq;

  pq.push(2);
  pq.push(4);
  pq.push(10);
  pq.emplace(7);

  cout << "Top: " << pq.top() << endl;

  pq.pop();

  cout << "Top: " << pq.top() << endl;

  // MIN Heap
  priority_queue<int,vector<int>,greater<int>> eq;

  eq.push(2);
  eq.push(4);
  eq.push(10);
  eq.emplace(7);

  cout << "Top: " << eq.top() << endl;

  return 0;
}
