#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<conio.h>

using namespace std;

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
    cout<<"Enter file name: ";
    //getchar();
    cin >>fname;
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
            case 8: cout<<"Bye Bye!"; break;
        }
        if(opt == 8) break;
        if(opt != 2)getchar();
    }

}
void create_new(FILE *f){
    char tm[100];
    strcpy(tm, fname);
    cout<<"Enter new file name: ";
    cin >> fname;
    f = fopen(fname, "wb");
    fclose(f);
    strcpy(fname, tm);
}
void change_file(){
    cout<<"Enter file name: ";
    //getchar();
    cin>>fname;
}
void statistic_opt(int a){
    if(a == 1) cout << "> ";
    cout <<"1. Statistics for scholarship." << endl;
    if(a == 2) cout <<"> ";
    cout << "2. Statistics for who doesn't pass." << endl;
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
                    cout << setw(3)<< s.num << setw(20) << s.name
                      << setw(8) << setprecision(3) << s.avr << " ";
                    for(k=0; s.marks[k + 1] != 0; k++){
                        cout << s.marks[k]<< ", ";
                    }
                    cout << s.marks[k] << endl;
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
void addToFile(FILE *f, int opt){
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

void deleteFromFile(FILE *f, FILE *tmp){
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
void readFromFile(FILE *f){
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
void editFile(FILE *f){
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
    cout<<"Data sorted successfully!";
}
void Check(int a){
    if(a == 1) cout <<"> ";
    cout <<"1. Add data to file." << endl;
    if(a == 2) cout <<"> ";
    cout <<"2. Change the used file." << endl;
    if(a == 3) cout <<"> ";
    cout <<"3. Delete data from file." << endl;
    if(a == 4) cout <<"> ";
    cout <<"4. View data from file." << endl;
    if(a == 5) cout <<"> ";
    cout <<"5. Edit data from a file." << endl;
    if(a == 6) cout <<"> ";
    cout <<"6. Sort data from a file." << endl;
    if(a == 7) cout <<"> ";
    cout <<"7. Get file statistics." << endl;
    if(a == 8) cout <<"> ";
    cout <<"8. Exit." << endl;
}
