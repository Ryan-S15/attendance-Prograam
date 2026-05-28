#include <iostream>
#include <string>
#include <fstream>
#include <vector> 
using namespace std;

int main() {
  vector<string> names = {}; 
  vector<string> attendance = {}; 
  string name; 
  string date; 
  int loop = 0; 
  int fail;
  int i, attendances; 

  cout << "enter date as month-day-year\n"; 
  cin >> date;
  ofstream MyFile (date + ".txt"); 
  cout << "how many students are there\n";
  cin >> i;
  do {
  cout << "enter students name\n"; 
  cin >> name;
  names.push_back(name); 
  do {
  fail = 0;
  cout << "are they present, yes(1) no(2)\n"; 
  cin >> attendances;
  if (attendances == 1){
  MyFile << name <<  ", attendance: present\n";
  attendance.push_back(", attendance: present\n");
  }
  else if (attendances == 2){
  MyFile << name <<  ", attendance: absent\n"; 
  attendance.push_back(", attendance: absent\n");
  } else {
  cout << "invalid input, try again\n"; 
  fail++;
  }
  } while (fail == 1); 
  loop++;
  } while (loop < i); 
  cout << endl;
  for (int x = 0; x < names.size(); x++){  
  cout << names[x] << attendance[x];
}
  MyFile.close();

  return 0;
}



