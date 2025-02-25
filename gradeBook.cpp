#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

int arrayAssign(string names[6], int grades[6][5]);
double calculateAvg(double averages[6], int grades[6][5]);
void getLetterGrades(double averages[6], char letterGrades[6]);

int main() {

  string names[6];
  int grades[6][5];
  double averages[6];
  char letterGrades[6];

  
  ifstream inputFile;
  inputFile.open("studentGrades.txt");
    if (!inputFile.is_open()) { //verify if file sucessfully opens
       cerr << "Error: Could not open the file." << endl; 
    return 1; // Exit program with error code
  }

  arrayAssign(names, grades);
  calculateAvg(averages, grades);
  getLetterGrades(averages,letterGrades);
 
  // Print the chart header
  cout << left << setw(20) << "Name" 
       << setw(10) << "Average" 
       << "Letter Grade" << endl;
  cout << setfill('-') << setw(40) << "" << setfill(' ') << endl; // Underline for header
  // Print each student's name, average, and letter grade
  for (int i = 0; i < 6; ++i) {
      cout << left << setw(20) << names[i]
           << setw(10) << fixed << setprecision(2) << averages[i]
           << letterGrades[i] << endl;
  }
  inputFile.close();
  
return 0;
}

int arrayAssign(string names[6], int grades[6][5]) { //function sorts names and grades into 2 parallel arrays
  ifstream inputFile("studentGrades.txt");
  
    for (int i = 0; i < 6; i++) {
      inputFile >> names[i];
        for(int j = 0; j < 5; j++){
          inputFile >> grades[i][j];
        }
     
    }
  return 0;
}
double calculateAvg(double averages[6], int grades[6][5]) { //takes grades for each student and puts the average in new parallel array. 
    for (int i = 0; i < 6; i++) {
        double sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += grades[i][j]; // Sum the grades for each student
        }
        averages[i] = sum / 5.0; // Calculate average and store in averages array
    }
    return 0;
}
void getLetterGrades(double averages[6], char letterGrades[6]) { //Function to convert avg and put them in parallel letter grade array 
    for (int i = 0; i < 6; i++) {
        if (averages[i] >= 91) {
            letterGrades[i] = 'A';
        } else if (averages[i] >= 81) {
            letterGrades[i] = 'B';
        } else if (averages[i] >= 71) {
            letterGrades[i] = 'C';
        } else if (averages[i] >= 61) {
            letterGrades[i] = 'D';
        } else {
            letterGrades[i] = 'F';
        }
    }
}