#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include<fstream>
#include<string>
#include"headers/student.h"
#include"headers/definitions.h"

using namespace std;

int main (){
    string fname = "";
    int n, m, i, k, j, dn, opt;
    float sum;
    //char input;
    opt = 0;
    cout<<"Enter file name: ";
    cin >>fname;
    ofstream ofs(fname);
	   ifstream ifs(fname);
    while(1){
        opt=0;
        cout<<endl;
        Check(opt);
        opt = cin.get();
        cout<<endl;
        switch(opt){
            case 1: addToFile(of); break;
            case 2: change_file(fname); break;
            case 3: deleteFromFile(f, tmp, fname); break;
            case 4: readFromFile(f, fname); break;
            case 5: editFile(f, fname); break;
            case 6: sort_data(f, fname); break;
            case 7: create_file(f); break;
            //case 8: does_not_pass(f, fname); break;
            case 9: cout<<"Bye Bye!"; break;
        }
        if(opt == 9) break;
        //if(opt != 2);getchar()
    }

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
    cout <<"7. Create new file." << endl;
    if(a == 8) cout <<"> ";
    cout <<"8. How doesn't pass." << endl;
    if(a == 9) cout <<"> ";
    cout <<"9. Exit." << endl;
}

// FUNCTION DEFINITIONS START HERE:
void create_file(FILE *f){
    string tm;
    tm = fname;
    cout <<"Enter new file name: ";
    getline(cin, fname);
    f = fopen(fname, "wb");
    fclose(f);
    fname = tm;
}
void change_file(fname){
    printf("Enter file name: ");
    getline(cin, fname);
}
/*void statistic_opt(int a){
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
}*/
void addToFile(ofs){
  Employee s;
  for (int i=0; 1 ; i++){
    cout << "Enter name: ";
    string name = "";
    getline(cin, name);
    if(name == ""){
        break;
    }
    s.setName(name);
    cout << endl;
    int salary = 0, Wdays = 0, Wddays = 0, Oh = 0, coef = 0;
    cout << "Enter Salary: ";
    cin >> Salary;
    s.setSalary(Salary);
    int Wdays;
    cout << "Enter work days for month: ";
    cin >> Wdays;
    s.setWday(Wdays);
    cout << "Enter worked days: "
    cin >> Wddays;
    s.setWddays(Wddays);
    cout << "Enter overtime worked hours";
    cin >> Oh;
    s.setOverHours(Oh);
    ofs << s.toString();
    ofs.close();
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
void readFromFile(FILE *ifs){
    Employee s;
    ifs.open//not sure if works
    while(string name << double salary << double workdays << double workddays << double Oh << double coef << double Opay
    << double Rpay) {
    cout << name << salary << workdays << workddays << Oh << coef << Opay << Rpay << endl;
    }
    ifs.close;
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
