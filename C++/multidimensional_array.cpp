#include <iostream>
// #include <cmath>
#define ROWS 3
#define COLS 3
using namespace std;

void display(int (&arr)[ROWS][COLS]){//Why (&arr) ? [] presedence is higher then &
  // int no_of_element=sizeof(arr)/sizeof(arr[0][1]);
  // int limit = sqrt(no_of_element);
  // for (int i=0;i<limit;i++){
  //   for(int j=0;j<limit;j++){
  //     cout << arr[i][j] << endl;
  //   }
  // }
  for (int i=0;i<ROWS;i++){
    for(int j=0;j<COLS;j++){
      cout << arr[i][j] << endl;
    }
  }
}

void get_arr(int (&arr)[ROWS][COLS]){
  cout << "Enter elements --> " << endl;
  for (int i=0;i<ROWS;i++){
    for(int j=0;j<COLS;j++){
      cout << " >> ";
      cin >> arr[i][j];
    }
  }
}

int main(){
  int arr[ROWS][COLS];
  get_arr(arr);
  display(arr);
  return 0;
}
