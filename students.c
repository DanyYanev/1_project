#include<stdio.h>

typedef struct{
    int num;
    char name[50];
    int marks[20];
    float avr;
}student;

void addToFile(FILE *f, int opt);
void deleteFromFile(FILE *f, FILE *tmp);
void readFromFile(FILE *f);
void Check(int a);
void statistic_types(FILE *f);
void statistic_opt(int a);
void get_scholarship(FILE *f);
void does_not_pass(FILE *f);
void sort_data(FILE *f);
void editFile(FILE *f);
void change_file();

char fname[100];
int main (){
    int n, m, i, k, j, dn, opt;
    float sum;
    FILE *f;
    FILE *tmp;
    char input;
    opt = 1;
    printf("Enter file name: ");
    getchar();
    gets(fname);
    while(1){
        system("cls");
        Check(opt);
        input = 0;
        while(input != 13){
            input = getch();
            system("cls");
            if(input == 72 && opt != 1){
                opt--;
            }else if(input == 80 && opt != 8){
                opt++;
            }else if(input == 80 && opt == 8){
                opt = 1;
            }else if(input == 72 && opt == 1){
                opt = 8;
            }
            Check(opt);
        }
        system("cls");
        switch(opt){
            case 1: addToFile(f, opt); break;
            case 2: change_file(); break;
            case 3: deleteFromFile(f, tmp); break;
            case 4: readFromFile(f); break;
            case 5: editFile(f); break;
            case 6: sort_data(f); break;
            case 7: statistic_types(f); break;
            case 8: printf("Bye Bye!"); break;
        }
        if(opt == 8) break;
        if(opt != 2)getchar();
    }

}
void create_new(FILE *f){
    char tm[100];
    tm = fname;
    printf("Enter new file name: ");
    getchar();
    gets(fname);
    f = fopen(fname, "wb");
    fclose(f);
    fname = tm;
}
void change_file(){
    printf("Enter file name: ");
    getchar();
    gets(fname);
}
void statistic_opt(int a){
    if(a == 1) printf("> ");
    printf("1. Statistics for scholarship.\n");
    if(a == 2) printf("> ");
    printf("2. Statistics for who doesn't pass.\n");
}
void statistic_types(FILE *f){
    int opt = 1, input = 0;
    statistic_opt(opt);
    while(1){
        system("cls");
        statistic_opt(opt);
        input = 0;
        while(input != 13){
            input = getch();
            system("cls");
            if(input == 72 && opt != 1){
                opt--;
            }else if(input == 80 && opt != 2){
                opt++;
            }else if(input == 80 && opt == 2){
                opt = 1;
            }else if(input == 72 && opt == 2){
                opt = 2;
            }
            statistic_opt(opt);
        }
        system("cls");
        switch(opt){
            case 1: get_scholarship(f); break;
            case 2: does_not_pass(f); break;
        }
        break;
    }
}
void get_scholarship(FILE *f){
    student s;
    int k;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                if(s.avr >= 5.5){
                    printf("%-3d", s.num);
                    printf("%-20s", s.name);
                    printf("%-8.2f", s.avr);
                    for(k=0; s.marks[k + 1] != 0; k++){
                        printf("%d, ", s.marks[k]);
                    }
                    printf("%d\n", s.marks[k]);
                }
            }

        }
        fclose(f);
    }
}
void does_not_pass(FILE *f){
    student s;
    int k, i;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                for(i = 0 ; s.marks[i] >= 2 && s.marks[i] <= 6 ; i++){
                    if(s.marks[i] == 2){
                        printf("%-3d", s.num);
                        printf("%-20s", s.name);
                        printf("%-8.2f", s.avr);
                        for(k=0; s.marks[k + 1] != 0; k++){
                            printf("%d, ", s.marks[k]);
                        }
                        printf("%d\n", s.marks[k]);
                        break;
                    }
                }
            }

        }
        fclose(f);
    }
}
void addToFile(FILE *f, int opt){
    if(opt == 1) f = fopen(fname, "ab");
    student s;
    int i, k = 0, sum;
    if(f){
        for (i=0; 1 ; i++){
            sum=0;
            printf("Enter number: ");
            scanf("%d", &s.num);
            if(s.num == 0){
                break;
            }
            getchar();
            printf("Enter name: ");
            gets(s.name);
            s.avr = 0;
            printf("Enter mark 1, for student number %d: ", s.num);
            scanf("%d", &s.marks[0]);
            s.avr += s.marks[0];
            for (k=1; s.marks[k - 1] != 0 ; k++){
                printf("Enter mark %d, for student number %d: ", k+1, s.num);
                scanf("%d", &s.marks[k]);
                s.avr += s.marks[k];
            }
            s.avr= s.avr/(k - 1);
            fwrite(&s, sizeof(s), 1, f);
        }
        fclose(f);
    }
}

void deleteFromFile(FILE *f, FILE *tmp){
    student s;
    int k, dn;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                printf("%-3d", s.num);
                printf("%-20s", s.name);
                printf("%-8.2f", s.avr);
                for(k=0; s.marks[k + 1] != 0; k++){
                    printf("%d, ", s.marks[k]);
                }
            printf("%d\n", s.marks[k]);
            }
        }
        fclose(f);
    }
    tmp = fopen("temp.tmp", "wb");
    f = fopen(fname, "rb");
    if(f && tmp){
        printf("\nWhich number should be deleted: ");
        scanf("%d", &dn);
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
void readFromFile(FILE *f){
    student s;
    int k;
    f = fopen(fname, "rb");
    if(f){
        while(!feof(f)){
            if(fread(&s, sizeof(s), 1, f)){
                printf("%-3d", s.num);
                printf("%-20s", s.name);
                printf("%-8.2f", s.avr);
                for(k=0; s.marks[k + 1] != 0; k++){
                    printf("%d, ", s.marks[k]);
                }
            printf("%d\n", s.marks[k]);
            }
        }
        fclose(f);
    }
}
void editFile(FILE *f){
    int en, k;
    student s, sn;
    f = fopen(fname, "rb+");
    printf("Which number should be edited: ");
    scanf("%d", &en);
    printf("Enter new number: ");
    scanf("%d", &sn.num);
    getchar();
    printf("Enter new name: ");
    gets(sn.name);
    sn.avr = 0;
    printf("Enter mark 1, for student number %d: ", sn.num);
    scanf("%d", &sn.marks[0]);
    sn.avr += sn.marks[0];
    for (k=1; sn.marks[k - 1] != 0 ; k++){
        printf("Enter mark %d, for student number %d: ", k+1, sn.num);
        scanf("%d", &sn.marks[k]);
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
void sort_data(FILE *f){
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
    printf("Data sorted successfully!");
}
void Check(int a){
    if(a == 1) printf("> ");
    printf("1. Add data to file.\n");
    if(a == 2) printf("> ");
    printf("2. Change the used file.\n");
    if(a == 3) printf("> ");
    printf("3. Delete data from file.\n");
    if(a == 4) printf("> ");
    printf("4. View data from file.\n");
    if(a == 5) printf("> ");
    printf("5. Edit data from a file.\n");
    if(a == 6) printf("> ");
    printf("6. Sort data from a file.\n");
    if(a == 7) printf("> ");
    printf("7. Get file statistics.\n");
    if(a == 8) printf("> ");
    printf("8. Exit.\n");
}
