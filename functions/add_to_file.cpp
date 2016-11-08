#include<iostream>
#include<stdio.h>
#include<fstream>
#include"../headers/student.h"
using namespace std;

void addToFile(string fname){
  Employee s;
  ofstream ofs;
  ofs.open(fname.c_str(), ios_base::app);
  while(1){
    cout << "Enter name: ";
    string name = "";
    cin >> name;
    if(!name.compare("none")){
        break;
    }
    s.setName(name);
    double salary = 0.0, Wdays = 0.0, Wddays = 0.0, Oh = 0.0, coef = 0.0;
    cout << "Enter Salary: ";
    cin >> salary;
    s.setSalary(salary);
    cout << "Enter work days for month: ";
    cin >> Wdays;
    s.setWday(Wdays);
    cout << "Enter worked days: ";
    cin >> Wddays;
    s.setWddays(Wddays);
    cout << "Enter overtime worked hours: ";
    cin >> Oh;
    s.setOverHours(Oh);
    ofs << s.toString();
    ofs.close();
  }
}
