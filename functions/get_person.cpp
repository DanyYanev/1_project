#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<fstream>
//#include<string>
#include"../headers/student.h"
using namespace std;

void get_person(string fname){
    Employee s;
    ifstream ifs;
    ifs.open(fname.c_str());
    cout << "Enter searched worker: ";
    string searched;
    bool found = false;
    cin >> searched;
    string name = "";
    double salary = 0.0, workdays = 0.0, workddays = 0.0, Oh = 0.0, coef  = 1.75,
      Opay = 0.0, Rpay = 0.0;
    while(ifs  >> name >> salary >>  workdays >>  workddays >>  Oh
      >> coef >>  Opay >>  Rpay) {
      if(searched.compare("none")){
          if(!name.compare(searched)){
            cout << name << ' ' << salary << ' ' << workdays << ' ' << workddays
              << ' ' << Oh << ' ' << coef << ' ' << Opay << ' ' << Rpay << ' ' << endl;
            found = true;
          }
      } else {
        found = true;
        cout << "Operation cancelled." << endl;
        break;
      }
    }
    if(found == false){
      cout << "Worker not found in database. Check if file is correct and try again. Exiting." << endl;
    }
    ifs.close();
}
