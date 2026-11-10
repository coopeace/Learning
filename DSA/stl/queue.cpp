#include <iostream>
#include <queue>

using namespace std;

// FIFO and O(1)

int main(){
  queue<int> q;

  q.push(12);
  q.push(45);
  q.push(93);

  q.emplace(88);

  cout << "back of queue: " << q.back() << endl;
  q.back()+=5;
  cout << "back of queue: " << q.back() << endl;

  cout << "Front of queue: " << q.front() << endl;

  cout << "Popped" << endl;

  cout << "Front of queue: " << q.front() << endl;
  return 0;
}
