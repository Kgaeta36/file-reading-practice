#include <fstream>
#include <iostream>
using namespace std;
/**
Title: Hw01-3.cpp
Abstract: Read an input filename from user and draw a vertical histogram for the
numbers. Author: Kimberly Gaeta Email: Kgaeta@csumb.edu Estimate: 1 hour Date:
1/30/2023
  **/
const int MAX = 7;
void printArray (int a[], int size);
void verticalHistogram (int a[], int x, int y);
int highestNumber (int a[], int x);
int main() {
  string file;
  cout << "Enter input file name: ";
  cin >> file;
  // open file
  ifstream fin;
  fin.open(file);
  if (fin.fail()) {
    cerr << "Couldn't open file\n";
    return 0;
  }
  cout << "\n===== Vertical Histogram =====\n";
  int num;
  int storage[MAX];
  for (int i = 0; i < MAX; i++){
    fin >> num;
    storage[i] = num;
    //cout << storage[i] << " ";
  } 
  int highest = highestNumber(storage, MAX);// WORKS!
  //cout << highest;
  verticalHistogram(storage, highest, MAX);// WORKS!
  cout << "-------------\n";
  printArray (storage, MAX);
    
  fin.close();
}
void printArray (int a[], int size){
  for (int i = 0; i < size; i++){
    cout << a[i] << " ";
  }
}
void verticalHistogram (int a[], int x, int y){
  for (int i = x; i > 0; i--){
    for (int k = 0; k < MAX; k++){
      if (i <= a[k]){
        cout << "* ";
      } else {
        cout << "  ";
      }
    }
    cout << "\n";
  }
}
int highestNumber (int a[], int x){
  int high = -1;
  for (int i = 0; i < x; i++){
    if (a[i] > high){
      high = a[i];
    }
  }
  return high;
}