#include<iostream>
#include<iomanip>

void showBalance(double balance){
  std::cout << "Your Balance is: $" << std::setprecision(2) << std::fixed << balance <<'\n';
}

double depositMoney(){
  double amount =0;
  std::cout << "Enter amount to be deposited:";
  std::cin >> amount;
  if(amount>0)
    return amount;
  else{
    std::cout << "That's not valid deposit.\n";
    return 0;
  }
}

double withdrawMoney(double balance){
  double amount =0;
  std::cout << "Enter amount to be withdrawn:";
  std::cin >> amount;
  if(amount>balance){
    std::cout << "Insuffiencient Funds.\n";
    return 0;
  }
  else if(amount < 0){
    std::cout << "That's not a valid amount.\n";
    return 0;
  }
  return amount;
}

int main(){
  double balance = 0.0;
  int choice =0;
  do{
    std::cout << "***********************\n";
    std::cout << "1.Show Balance\n";
    std::cout << "2.Deposit Money\n";
    std::cout << "3.Withdraw Money\n";
    std::cout << "4.Exit\n";
    std::cout << "***********************\n";
    std::cout << "Enter your choice:";
    std::cin >> choice;

    switch(choice){
      case 1:
        showBalance(balance);
        break;
      case 2:
        balance += depositMoney();
        showBalance(balance);
        break;
      case 3:
        balance -= withdrawMoney(balance);
        showBalance(balance);
        break;
      case 4:
        std::cout << "\nThank you visiting!!\n";;
        break;
      default:
        std::cout << "Invalid Choice\n";
        std::cout << "Enter another choice\n";
    }
  }while(choice!=4);

  return 0;
}
