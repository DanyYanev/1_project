#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<fstream>
//#include<string>
#include"../headers/student.h"
using namespace std;

void readFromFile(string fname){
    Employee s;
    ifstream ifs;
    ifs.open(fname.c_str());
    string name = "";
    double salary = 0.0, workdays = 0.0, workddays = 0.0, Oh = 0.0, coef  = 1.75,
      Opay = 0.0, Rpay = 0.0;
    while(ifs  >> name >> salary >>  workdays >>  workddays >>  Oh
      >> coef >>  Opay >>  Rpay) {
    cout << name << ' ' << salary << ' ' << workdays << ' ' << workddays
      << ' ' << Oh << ' ' << coef << ' ' << Opay << ' ' << Rpay << ' ' << endl;
    }
    ifs.close();
}
