#include <iostream>
#include <utility>

using namespace std;

int main () {
  pair<int,int> p = {1,3};
  cout << p.first << " " << p.second << endl;
  pair <int,pair<int,int>> q = {7,p};
  cout << q.first << " " << q.second.first << " " << q.second.second << endl;
  pair <char,char> alphabet[] = {{'a','b'},{'g','h'},{'m','w'}};
  cout << alphabet[1].second << endl;
  return 0;
}
