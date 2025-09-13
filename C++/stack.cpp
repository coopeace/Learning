#include<iostream>

int push(int arr[],int top);
int pop(int arr[],int top);
void display(int arr[],int top);

int main(){
  int arr[5];
  int choice,top=-1;
  while(1){
    std::cout << "-------------------------\n";
    std::cout << "-          MENU         -\n";
    std::cout << "-------------------------\n";
    std::cout << "1.Push\n2.Pop\n3.Display\n4.Quit\n";
    std::cout << "-------------------------\n";
    std::cout << "Enter your choice:";
    std::cin >> choice;
    switch(choice){
      case 1:top = push(arr,top);
             break;
      case 2:top = pop(arr,top);
             break;
      case 3:display(arr,top);
             break;
      case 4:return 0;
             break;
      default:
             std::cout << "Invalid Choice!!\n.Enter another time.\n";
    }
  }
	return 0;
}

int push(int arr[],int top){
  if(top == 4){
    std::cout << "Stack Overflow.\n";
  }
  else{
    top++;
    std::cout << "Enter a element:";
    std::cin >> arr[top];
    std::cout << arr[top] << " is pushed.\n";
  }
  return top;
}

int pop(int arr[],int top){
  if(top == -1){
    std::cout << "Stack Underflow\n";
  }
  else{
    std::cout << arr[top] << " is popped.\n";
    top--;
  }
  return top;
}

void display(int arr[],int top){
  std::cout << "Elements inside stack:\n";
  for(int i=top;i>=0;i--){
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}
