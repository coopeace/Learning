#include <iostream>
using namespace std;

int main(){
  int candidates[] = {1,2,3,4,5},
      votes[] = {1,5,6,2,1,3,6,4,2,2,4,5,1,2,1,9,0,1,2,4},
      one,two,three,four,five,spoiled_votes;
  one=two=three=four=five=spoiled_votes=0;
  // int no_of_votes = sizeof(votes);
  for (int vote : votes){
      switch (vote) {
        case 1 : one += 1; break;
        case 2 : two += 1; break;
        case 3 : three += 1; break;
        case 4 : four += 1; break;
        case 5 : five += 1; break;
        default : spoiled_votes += 1;
      }
  }
  
  cout << "Votes of Candidate 1: " << one << endl; 
  cout << "Votes of Candidate 2: " << two << endl;
  cout << "Votes of Candidate 3: " << three << endl;
  cout << "Votes of Candidate 4: " << four << endl;
  cout << "Votes of Candidate 5: " << five << endl;
  cout << "spoiled Votes: " << spoiled_votes << endl;

  return 0;
}

