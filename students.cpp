#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include<cstring>
#include"headers/student.h"
#include"headers/definitions.h"

using namespace std;

int main (){
    char fname[100];
    int n, m, i, k, j, dn, opt;
    float sum;
    FILE *f;
    FILE *tmp;
    char input;
    opt = 0;
    cout<<"Enter file name: ";
    cin >>fname;
    while(1){
        opt=0;
        cout<<endl; 
        Check(opt);
        cin>>opt;
        getchar();
        cout<<endl;
        switch(opt){
            case 1: addToFile(f, opt, fname); break;
            case 2: change_file(fname); break;
            case 3: deleteFromFile(f, tmp, fname); break;
            case 4: readFromFile(f, fname); break;
            case 5: editFile(f, fname); break;
            case 6: sort_data(f, fname); break;
            case 7: get_scholarship(f, fname); break;
            case 8: does_not_pass(f, fname); break;
            case 9: cout<<"Bye Bye!"; break;
        }
        if(opt == 9) break;
        if(opt != 2)getchar();
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
    cout <<"7. Who gets scholarship." << endl;
    if(a == 8) cout <<"> ";
    cout <<"8. How doesn't pass." << endl;
    if(a == 9) cout <<"> ";
    cout <<"9. Exit." << endl;
}
