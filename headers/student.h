#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<sstream>

using namespace std;

class Employee{
    protected:
        string name;
        double Rpay, Opay, salary, Oh, Ocoef, workddays, workdays;
    public:
        Employee() {
            name = "";
            Rpay = 0;
            Opay = 0;
            salary = 0;
            Oh = 0;
            Ocoef = 1.75;
            workdays = 0;
            workddays = 0;
        }
        ~Employee(){}
        string getName() {
          return name;
        }
        void setName(std::string empName){
          name = empName;
        }
        double getSalary(){
          return salary;
        }
        double getWddays(){
          return workddays;
        }
        void setWday(double days){
          workdays = days; //work days for the month
        }
        void setWddays(double days){
          workddays = days; //worked days
        }
        void setSalary(double MSalary){
          salary = MSalary; //monthly salary
        }
        double setOverHours(double oh){
          Oh = oh; //overhours
        }
        double setOcoef(double coef){
          Ocoef = coef;
        }
        double getOPay(){
          return Opay = Oh*salary/workdays/8*Ocoef;
        }
        double getRPay(){
          return Rpay = salary/workdays*workddays; // works dont question
        }
        double getWage(){
            int wage = getRPay() + getOPay();
            return wage;
        }
        string toString(){
            stringstream stm;
            stm << name << " " << salary << " " << workdays << " "
            << workddays << " " << Oh << " " << Ocoef << " "
            << getOPay() << " " << getRPay() << endl;
            return stm.str();
        }


};


#endif
