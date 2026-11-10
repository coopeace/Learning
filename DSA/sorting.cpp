#include <iostream>
#include <utility>

using namespace std;

void printArray(const int arr[],int n){
  for (int i =0; i < n ; i++){
    cout << arr[i] << " ";
  } 
  cout << endl;
}

void bubbleSort(int arr[],int n){
  for (int i=0; i<n ; i++){
    for (int j=0; j<n-i-1; j++){
      if (arr[j]>arr[j+1]){
        swap(arr[j],arr[j+1]);
      }
    }
  }
}

int main () {
  int arr[] = {3,89,21,1,55};

  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Before:\n" ;
  printArray(arr,n);

  bubbleSort(arr, n);

  cout << "After:\n" ;
  printArray(arr,n);

  return 0;
}
