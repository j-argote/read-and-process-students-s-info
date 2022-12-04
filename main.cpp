#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int NUMBER_OF_GRADES = 3;

int main(){
  fstream inFS;
  ofstream outFS;
  string textFile, fullName;
  int entries, grade1, grade2, grade3, avg, highestAvg, lowestAvg, temp;
  char letterGrade;
  vector<string> namesVect;
  vector<int> gradesVect;
  
  //read in string; used as the input file name
  cin >> textFile;
  
  //open text file to read
  inFS.open(textFile);
  if(!inFS.is_open()){
    cout << "could not open read file" << endl;
    return 1;
  }
  //open text file to write
  outFS.open("output.txt");
  if(!outFS.is_open()){
    cout << "could not open output file" << endl;
    return 1;
  }
  
  //read in text file
  //read in first a int; number of entries
  inFS >> entries;
  inFS.ignore();
  
  //read in a string followed by 3 integers
  //compute the avg of both students
  for(int i = 0; i < entries; i++){
    getline(inFS, fullName);
    inFS >> grade1 >> grade2 >> grade3;
    avg = (grade1 + grade2 + grade3) / NUMBER_OF_GRADES;
    inFS.ignore();
    namesVect.push_back(fullName);
    gradesVect.push_back(avg);
  }

  highestAvg = gradesVect.at(0);
  lowestAvg = gradesVect.at(0);
  for(int i = 0; i < entries; i++){
    if(highestAvg < gradesVect.at(i)){
      highestAvg = gradesVect.at(i);
    }
    if(lowestAvg > gradesVect.at(i)){
      lowestAvg = gradesVect.at(i);
    }
  }
  outFS << "Highest grade: " << highestAvg << endl;
  outFS << "Lowest grade: " << lowestAvg << endl;
  outFS << endl;
  
  for(int i = 0; i < entries; i++){
    if(gradesVect.at(i) <= 100 && gradesVect.at(i) >= 92){
      letterGrade = 'A';
    }
    else if(gradesVect.at(i) < 92 && gradesVect.at(i) >= 80){
      letterGrade = 'B';
    }
    else if(gradesVect.at(i) < 80 && gradesVect.at(i) >= 70){
      letterGrade = 'C';
    }
    else if(gradesVect.at(i) < 70 && gradesVect.at(i) >= 60){
      letterGrade = 'D';
    }
    else{
      letterGrade = 'F';
    }
    
    outFS << namesVect.at(i) << ": " << letterGrade << endl;
  }
  
  
  //close read file
  inFS.close();
  outFS.close();
  return 0;
}