#include<iostream>
#include<stdio.h>
#include"../headers/student.h"
using namespace std;

void addToFile(FILE *f, int opt, char *fname){
    if(opt == 1) f = fopen(fname, "ab");
    student s;
    int i, k = 0, sum;
    if(f){
        for (i=0; 1 ; i++){
            sum=0;
            cout <<"Enter number: ";
            cin >> s.num;
            if(s.num == 0){
                break;
            }
            getchar();
            cout << "Enter name: ";
            cin >>s.name;
            s.avr = 0;
            cout <<"Enter mark 1 for student number "<< s.num<<": ";
            cin >> s.marks[0];
            s.avr += s.marks[0];
            for (k=1; s.marks[k - 1] != 0 ; k++){
                cout <<"Enter mark "<< k+1 <<" for student number " <<s.num
                <<": ";
                cin >> s.marks[k];
                s.avr += s.marks[k];
            }
            s.avr= s.avr/(k - 1);
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
    }
}
