#include<iostream>

void bubble(int arr[],int size);

void printarr(int arr[],int size);

int main(){
  int arr[]={1,2,34,68,43,673,19,90};
  int size=sizeof(arr)/sizeof(arr[0]);

  std::cout << "Before Sorting:\n";
  printarr(arr,size);

  bubble(arr,size);

  std::cout << "After Sorting:\n";
  printarr(arr,size);

  return 0;
}

void printarr(int arr[],int size){
  for(int i=0;i<size;i++){
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

void bubble(int arr[],int size){
  int temp;
  for(int i=0;i<size-1;i++){
    for(int j=0;j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1]= temp;
      }
    }
  }
}
