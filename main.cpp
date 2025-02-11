#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

int arrayAssign(string names[6], int grades[6][5]);

int main() {

  string names[6];
  int grades[6][5];
  //double averages[6];
  
  ifstream inputFile;
  inputFile.open("studentGrades.txt");
  arrayAssign(names, grades);
   
  for (string person : names){
    cout << person << " ";
  }
  for (int i = 0; i < 6; ++i) { // Iterate over rows
    for (int j = 0; j < 5; ++j) { // Iterate over columns
      std::cout << grades[i][j] << " ";
    }
    cout << endl;
  }
  inputFile.close();
  
return 0;
}

int arrayAssign(string names[6], int grades[6][5]){
  ifstream inputFile("studentGrades.txt");
  
    for (int i = 0; i < 6; i++) {
      getline(inputFile, names[i]);
      for(int j = 0; j < 5; j++) {
        inputFile >> grades[i][j];
      }
      inputFile.ignore(); // Skip newline after grades
    }
  return 0;
}