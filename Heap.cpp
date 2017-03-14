#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


void printTree(int arraySize, int array[100]);
void buildTree(int index, int array[100]);
void removeNode(int &arraySize, int array[100]);

int main(){
  int array[100];
  char array1[205];
  char temp[10] = "";
  int arraySize = 0;
  int length;

  cout << "Hello, enter your numbers. The tree will print first, followed by the max heap (largest to smallest)" << endl;
  cin.getline(array1, 205);
  length = strlen(array1);
  //Put numbers into array, convert into int and put into integer array
  for (int i = 0; i <= length; i++){
    if(array1[i] != ' ' && array1[i] != '\0'){
      strncat(temp, array1 + i, 1);
    }
    else{
      if (strlen(temp)>0) {
         int x = atoi(temp);
         temp[0] = '\0';
         array[arraySize] = x;
         arraySize++;
         buildTree(arraySize - 1, array);
      }	 
    }
  }
  /*
  cout << "Length" << arraySize << endl;
  for (int i = 0; i < arraySize; i++){
    cout << array[i] << endl;
  }
  */
  printTree(arraySize, array);
  cout << "Max Heap" << endl;
  removeNode(arraySize, array);
}

//Build tree
void buildTree(int childIndex, int array[100]){
  int parentIndex;
  int temp;
  int index = childIndex;
  if (index==0){
    return;
  }
  
  if(index % 2 == 0){
    //cout << "Even";
    parentIndex = (index-2)/2;
  }
  if(index % 2 == 1){
    //cout << "Odd";
    parentIndex = (index-1)/2;
    
  }
  while (index > 0 && array[index] > array[parentIndex]){
    temp = array[index];
    array[index]=array[parentIndex];
    array[parentIndex] = temp;
    
    index = parentIndex;
    
    if(index % 2 == 0){
      //      cout << "Even";
      parentIndex = (index-2)/2;
    }
    if(index % 2 == 1){
      //      cout << "Odd";
      parentIndex = (index-1)/2;

    }

    
  }
  
  
}
//Removes the largest node and adds it to the output
void removeNode(int &arraySize, int array[100]){
  if(arraySize == 0){
    return;
  }
  while(arraySize != 0){
    cout << array[0] << " ";
    array[0] = array[arraySize - 1];
    arraySize--;
    int index = 0;
    int maxChild;
    int moveDown =1;


    while (moveDown ==1) {
      //Case: No Child
      if(2*index + 1 > arraySize - 1){
        maxChild = -1;
      }
      //Left Child
      else if(2*index + 1 <= arraySize - 1 && 2*index + 2 > arraySize - 1){
        maxChild = 2*index + 1;
      }
      //Left Child is larger
      else if(array[2*index + 1] >= array[2*index + 2]){
        maxChild = 2*index + 1;
      }
      //Right Child is larger 
      else{
	maxChild = 2*index + 2;
      }
      //Switch with the larger child
      if(maxChild > 0 && array[index] < array[maxChild]){
	int temp = 0;
	temp = array[index];
	array[index] = array[maxChild];
	array[maxChild] = temp;
	index = maxChild;
      }
      else
	{ // it is larger than child, stop moveDown
	  moveDown =0;
	}
    }

  }
}

//Visual representation of the tree
void printTree(int arraySize, int array[100]){
  for (int i = 0; i < arraySize; i++){
    // Whenever each level of the tree is filled, go to the next line
    if (i == 1 || i == 3 || i == 7 || i == 15 || i == 31 || i == 63){
      cout << endl;
    }
    cout << array[i] << "  ";
  }
  cout << endl;
}
