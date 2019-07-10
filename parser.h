#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

FILE* openFILE (char* filename);
FILE* openFILEwrite(char* filename);
int parser_EmployeeFromText(FILE* pFile , void* this);
int parser_EmployeeListToText (FILE* pFile, void* this);
