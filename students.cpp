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
    int opt;
    //char input;
    opt = 0;
    cout<<"Enter file name: ";
    cin >>fname;
    while(1){
        opt=0;
        cout<<endl;
        Check(opt);
        cin >> opt;
        cout<<endl;
        switch(opt){
            case 1: addToFile(fname); break;
            case 2: fname = change_file(); break;
            case 3: readFromFile(fname); break;
            case 4: cout<<"Bye Bye!\n"; break;
        }
        if(opt == 4) break;
        //if(opt != 2);getchar()
    }

}

void Check(int a){
    cout <<"1. Add data to file." << endl;
    cout <<"2. Change the used file." << endl;
    cout <<"3. View data from file." << endl;
    cout <<"4. Exit." << endl;
}
