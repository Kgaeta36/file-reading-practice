#include <iostream>
#include <fstream>
using namespace std;
/**
Title: Hw01-2.cpp
Abstract: Read an input filename from user and draw a horizontal histogram for the numbers.
Author: Kimberly Gaeta
Email: Kgaeta@csumb.edu
Estimate: 1 hour
Date: 1/29/2023
  **/
const int MAX = 5;
int main() {
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
  cout << "\n===== Horizontal Histogram =====\n";
  int length;
  for (int i = 0; i < MAX; i++){
    fin >> length;
    cout << length << ": ";
    for (int k = 0; k < length; k++){
      cout << "* ";
    }
    cout << "\n";
  } 
}