#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(){
  int array[100];
  char array1[205];
  char temp[10] = "";
  int arraySize = 0;
  int length;

  
  cout << "Hello" << endl;
  cin.getline(array1, 205);
  length = strlen(array1);
  for (int i = 0; i <= length; i++){
    if(array1[i] != ' ' && array1[i] != '\0'){
      strncat(temp, array1 + i, 1);
    }
    else{
      int x = atoi(temp);
      temp[0] = '\0';
      array[arraySize] = x;
      arraySize++;
    }
  }
  cout << "Length" << arraySize << endl;
  for (int i = 0; i < arraySize; i++){
    cout << array[i] << endl;
  }
  

  
}

void printTree(int size, int array[100]){
  
}
