
#include "complex.h" 
#include <ctype.h> /* For isdigit */
#include <string.h> /* For string manipulation functions */
#include <stdlib.h> /* for atof */

#define LINE_LEN 100 /* Maximum length of a line input */
#define NUM_FUNC 9  /* Number of commands */

/* Macros to check common errors */

#define EXTRANEOUS_TEXT(ch) \
    if (ch) {\
        printf("Extraneous text after end of command\n");\
        return;\
    }

#define MISSING_PARAMETER(ch) \
    if (!ch) {\
        printf("Missing parameter\n");\
        return;\
    }

#define MISSING_COMMA(ch) \
    if (ch != ',') {\
        printf("Missing comma\n");\
        return;\
    }

#define MULTIPLE_CONSECUTIVE_COMMAS(ch) \
    if (ch == ',') {\
        printf("Multiple consecutive commas\n");\
        return;\
    }

/* Enumeration to represent command names */
enum names {
    READ_COMP,          /* Command that places values in a complex variable */
    PRINT_COMP,         /* Command that prints a complex number */
    ADD_COMP,           /* Command that receives two complex numbers, sums them and prints the result */
    SUB_COMP,           /* Command that receives two complex numbers, subtracts them and prints the result */
    MULT_COMP_REAL,     /* Command that calculates the multiplication of a complex number and a real number received and prints the result */
    MULT_COMP_IMG,      /* Command that calculates the multiplication of a complex number and an imaginary number received and prints the result */
    MULT_COMP_COMP,     /* Command that calculates the multiplication of two complex numbers received and prints the result */
    ABS_COMP,           /* Command that calculates the absolute value of the complex number received and prints the result */
    STOP                /* Command that stop the program and print a goodbye message */
};


/* A function that performs the entire process of the program and the user interaction using other functions */
void programStart(char line[]);

/* A function that initializes the complex variables to a value of 0 + 0i */
void initialization();

/* A function that check if EOF reched and if not printing the line the user entered */
void inputLine(char line[]);

/* A function that receives an input line and do the command or print errors, according to user input */
void fixLine(char line[]);

/* A function that stop the program and print a goodbye message */
void stop();

/* A function that gets a pointer to the beginning of the first word in a command and returns a number representing the command or -1 if the string is not a command */
int firstWord(char *line);

/* A function that receives a string and returns a pointer to the first non-white character in the string */
char *skipBlank(char *s);

/* A function to remove all spaces from a given string */
void removeSpaces(char *str);      

/* A function that skip a number in a string and returns a pointer to the first char after the number */
char *skipNum(char *s);

/* A function that returns a pointer to a complex variable based on a given char */
complex *sortComplex(char x);    

/* A function that checks if a given character represents a valid complex variable it will returns 1 if valid, 0 otherwise */
int isComplex(char x);


