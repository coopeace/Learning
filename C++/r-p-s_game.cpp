#include<iostream>
#include<ctime>

char getUserchoice(){

  char player;
  do{
  std::cout << "Rock-Paper-Scissors Game\n";
  std::cout << "*****************************\n";
  std::cout << "1.'r'-rock\n2.'p'-paper\n3.'s'-scissor\n";
  std::cout << "Your Choice:";
  std::cin >> player;

  }while(player!='p' && player != 'r' && player !='s');
  return player;
}

char getComputerChoice(){
  srand(time(0));
  int num = (rand()%3)+1;

  switch(num){
    case 1: return 'r';
    case 2: return 'p';
    case 3: return 's';
  }
  return 0;
}

void showchoice(char choice){

  switch(choice){
    case 'r': std::cout << "Rock\n";
            break;
    case 'p': std::cout << "Paper\n";
            break;
    case 's': std::cout << "Scissors\n";
            break;
  }
}

void chooseWinner(char player,char computer){
  switch(player){
    case 'r':
      if(computer =='r'){
        std::cout << "It's a tie.\n";
      }
      else if(computer == 'p'){
        std::cout << "Computer Wins.\tPlayer Lose.\n";
      }
      else{
        std::cout << "Player Wins.\tComputer Lose.\n";
      }
      break;
    case 'p':
      if(computer =='p'){
        std::cout << "It's a tie.\n";
      }
      else if(computer == 's'){
        std::cout << "Computer Wins.\tPlayer Lose.\n";
      }
      else{
        std::cout << "Player Wins.\tComputer Lose.\n";
      }
      break;
    case 's':
      if(computer =='s'){
        std::cout << "It's a tie.\n";
      }
      else if(computer == 'r'){
        std::cout << "Computer Wins.\tPlayer Lose.\n";
      }
      else{
        std::cout << "Player Wins.\tComputer Lose.\n";
      }
      break;
  }
}

int main(){

  char player,computer;

  player = getUserchoice();
  std::cout << "\nPlayer choice:";
  showchoice(player);

  computer=getComputerChoice();
  std::cout << "Computer's choice:";
  showchoice(computer);

  chooseWinner(player,computer);
  return 0;
}
