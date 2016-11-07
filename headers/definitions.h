#ifndef DEFINITIONS_H
#define DEFINITIONS_H

void addToFile(FILE *f, int opt, char *fname);
void deleteFromFile(FILE *f, FILE *tmp, char *fname);
void readFromFile(FILE *f, char *fname);
void Check(int a);
void get_scholarship(FILE *f, char *fname);
void does_not_pass(FILE *f, char *fname);
void sort_data(FILE *f, char *fname);
void editFile(FILE *f, char *fname);
void create_file(FILE *f);
void change_file(char *fname);

#endif
