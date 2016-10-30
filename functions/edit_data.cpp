#include<iostream>
#include<stdio.h>
#include"../headers/student.h"
using namespace std;

void editFile(FILE *f, char *fname){
    int en, k;
    student s, sn;
    f = fopen(fname, "rb+");
    cout << "Which number should be edited: ";
    cin >>en;
    cout <<"Enter new number: ";
    cin >> sn.num;
    cout <<"Enter new name: ";
    cin >> sn.name;
    sn.avr = 0;
    cout <<"Enter mark 1, for student number " << sn.num <<": ";
    cin >> sn.marks[0];
    sn.avr += sn.marks[0];
    for (k=1; sn.marks[k - 1] != 0 ; k++){
        cout <<"Enter mark "<< k+1 <<" for student number" <<sn.num
        <<": ";
        cin >> sn.marks[k];
        sn.avr += sn.marks[k];
    }
    sn.avr= sn.avr/(k - 1);

    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                if(s.num == en){
                    fseek(f, -1*sizeof(s), SEEK_CUR);
                    fwrite(&sn, sizeof(sn), 1, f);
                    break;
                }
            }
        }
        fclose(f);
    }
}
