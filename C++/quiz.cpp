#include<iostream>
#include <string>

int main(){

  //Array of QUESTIONS
  std::string questions[] = {
    "What year C++ wad created?",
    "What is the predecessor of C++?",
    "What's C++ creator's name?"
  };

  //2-D Array of Options to QUESTIONS
  std::string options[][4] = {
    {"A.1969","B.1975","C.1985","D.1989"},
    {"A.ALGOL","B.Lisp","C.Java","D.C"},
    {"A.Guldo van rossum","B.Bjarne Stroustrup","C.John Carmack","D.Mark Zuckerberg"}
  };

  //Answerkey to QUESTIONS
  char answerkey[]={'C','D','B'};

  int no_of_questions = sizeof(questions)/sizeof(questions[0]);
  int no_of_options = sizeof(options[0])/sizeof(options[0][0]);
  char guess;
  int score=0;

  //Quiz
  for(int i=0;i<no_of_questions;i++){
    std::cout << "***************************\n";
    std::cout << questions[i] << '\n';

    for(int j=0;j<no_of_options;j++){
      std::cout << options[i][j] << '\n';
    }

    std::cout << "Choice:";

    std::cin >> guess;
    guess = toupper(guess);

    if(guess==answerkey[i]){
      std::cout << "CORRECT.\n";
      score++;
    }
    else{
      std::cout << "WRONG.\n";
      std::cout << "Correct Answer:" << answerkey[i] << '\n'; 
    }
  }

  //RESULTS
  std::cout << "***************************\n";
  std::cout << "*          RESULTS        *\n";  
  std::cout << "***************************\n";
  std::cout << "CORRECT GUESSES:"<< score << '\n';
  std::cout << "NO OF QUESTIONS::"<< no_of_questions << '\n';
  std::cout << "SCORE:"<< (score/(double)no_of_questions)*100<< '%' << '\n';
  std::cout << "***************************\n";
}
