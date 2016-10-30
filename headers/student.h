#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include <sstream>

class Employee{
    protected:
        std::string name;
        double pay, Opay, salary, Oh, Ocoef, workddays, workdays;
    public:
        Employee() {
            name = "";
            pay = 0; //per hours
            Opay = 0;
            salary = 0;
            Oh = 0;
            Ocoef = 1.75;
            workdays = 0;
            workddays = 0;
        }
        Employee (std::string empName){
            name = empName;
        }
        ~Employee(){}
        std::string getName() {
            return name;
        }
        void setName(std::string empName){
            name = empName;
        }
        double getSalary(){
            return salary;
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
          return Oh*pay*Ocoef;
        }
        double getPay(){
          return pay*workddays/8;
        }
        double getWage(){
            int wage = getPay() + getOPay();
            return wage;
        }
        /*string toString(){
            stringstream stm;
            stm << name << ": ";
            return stm.str();
            }
        */

};


#endif
