#include<iostream>
#include<stdio.h>
#include<iomanip>
#include"../headers/student.h"
using namespace std;

void deleteFromFile(FILE *f, FILE *tmp, char *fname){
    student s;
    int k, dn;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
              cout << setw(3)<< s.num << setw(20) << s.name
                << setw(8)  << setprecision(3) << s.avr;
                for(k=0; s.marks[k + 1] != 0; k++){
                    cout << s.marks[k]<< ", ";
                }
                cout << s.marks[k] << endl;
            }
        }
        fclose(f);
    }
    tmp = fopen("temp.tmp", "wb");
    f = fopen(fname, "rb");
    if(f && tmp){
        cout << endl << "Which number should be deleted: ";
        cin >> dn;
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                if(s.num != dn) fwrite(&s, sizeof(s), 1, tmp);;
            }
        }
        fclose(f);
        fclose(tmp);

        tmp = fopen("temp.tmp", "rb");
        f = fopen(fname, "wb");
        while(!feof(tmp)){
            if(fread(&s, sizeof(s), 1, tmp)){
                fwrite(&s, sizeof(s), 1, f);
            }
        }
        fclose(f);
        fclose(tmp);
    }
}
