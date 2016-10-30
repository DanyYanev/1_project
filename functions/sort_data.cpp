#include<iostream>
#include<stdio.h>
#include"../headers/student.h"
using namespace std;

void sort_data(FILE *f, char *fname){
    student studs[100], s, temp;
    int en, k, i, stud_size, flag = 1;
    f = fopen(fname, "rb");
    if(f){
        for(i = 0 ; !feof(f) ; i++){
            if(fread(&s, sizeof(s), 1, f)){
                studs[i] = s;
            }
        }
        stud_size = i - 1;
        fclose(f);
    }
    while(flag){
        flag = 0;
        for (i=0; i < stud_size - 1; i++){
            if (studs[i+1].num < studs[i].num){
                temp = studs[i];
                studs[i] = studs[i+1];
                studs[i+1] = temp;
                flag = 1;
            }
        }
    }
    f = fopen(fname, "wb");
    if(f){
        for(i = 0 ; i < stud_size ; i++){
            s = studs[i];
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
    }
    cout<<"Data sorted successfully!";
}
