#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
  string line;
  
    for (int i = 0; i < 6; i++) {
      getline(inputFile, line);
      istringstream iss(line);
      iss >> names[i];
      for(int j = 0; j < 5; j++){
        iss >> grades[i][j];
      }
    }
  return 0;
}