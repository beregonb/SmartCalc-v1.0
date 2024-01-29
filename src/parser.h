#ifndef PARSER_H
#define PARSER_H

typedef struct in_out {
    char *in;
    char *out;
} in_out;

void readLine(char **str);
void memory_out(in_out *myStruct);
void parser(in_out *myStruct);
void out_copy(in_out *myStruct, char *str, int *lenght_out);

#endif