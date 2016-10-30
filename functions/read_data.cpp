#include<iostream>
#include<stdio.h>
#include<iomanip>
#include"../headers/student.h"
using namespace std;

void readFromFile(FILE *f, char *fname){
    student s;
    int k;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
              cout << setw(3)<< s.num << setw(20) << s.name
                << setw(8) << setprecision(3) << s.avr << " ";
                for(k=0; s.marks[k + 1] != 0; k++){
                    cout << s.marks[k]<< ", ";
                }
                cout << s.marks[k] << endl;
            }
        }
        fclose(f);
    }
}
