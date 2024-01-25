#include <iostream>
#include <fstream>
using namespace std;
/** 
Title: Hw01-1.cpp
Abstract: This program reads an input file name from the user and will display the minimum number and dsipplay how many time each number was in the file.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Estimate: 2 hours
Date: 1/29/2023
  **/
const int MAX = 30;
void minNumber (int a[], int x);
void numCounter (int a[], int x);
int main(){
  string file;
  cout << "Enter input file name: ";
  cin >> file;
  // open file
  ifstream fin;
  fin.open(file);
  if(fin.fail()){
    cerr << "Couldn't open file\n";
    return 0;
  }
  int storage[MAX];
  int size;
  fin >> size;
  // (test) cout << size;
  int num;
  for (int i = 0; i < size; i++){
    fin >> num;
    storage[i] = num;
  }
  minNumber (storage, size); // WORKS!! do counter next
  numCounter (storage, size);// WORKS TOO <3
  /* (test)
  for (int i = 0; i < size; i++){
    cout << storage[i] << " ";
  } 
  */
  fin.close();
}
void minNumber (int a[], int x){
 int lowest = 100;
  for (int i = 0; i < x-1; i++){
    if (lowest > a[i]){
      lowest = a[i]; 
  }
    }
  cout << "\nMin Number: " << lowest << endl;
}
void numCounter (int a[], int x){
int freq[x];//keep track of frequency
int visited = -1;
for (int i = 0; i < x; i++){
  int count = 1;
  for (int k = i+1; k < x; k++){
    if (a[i] == a[k]){
      count++;
      freq[k] = visited;
    }
  }
    if (freq[i]!= visited){
      freq[i] = count;
}
    }
      
cout << "\nNumber" << "\t" << "Count\n";
for (int i = 0; i < x; i++){
  if (freq[i] != visited){
    cout << a[i] << "\t\t" << freq[i] << "\n";
  }
}
}