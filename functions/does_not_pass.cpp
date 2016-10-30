#include<iomanip>
#include<iostream>
#include<stdio.h>
#include"../headers/student.h"
using namespace std;
void does_not_pass(FILE *f, char *fname){
    student s;
    int k, i;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                for(i = 0 ; s.marks[i] >= 2 && s.marks[i] <= 6 ; i++){
                    if(s.marks[i] == 2){
                      cout << setw(3)<< s.num << setw(20) << s.name
                        << setw(8) << setprecision(3) << s.avr << " ";
                        for(k=0; s.marks[k + 1] != 0; k++){
                            cout << s.marks[k]<< ", ";
                        }
                        cout << s.marks[k] << endl;
                        break;
                    }
                }
            }

        }
        fclose(f);
    }
}
