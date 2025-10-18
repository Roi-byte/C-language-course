
#include "mycomp.h"
/* Declare the complex variables */
complex A, B, C, D, E, F;

/* The main method: */
int main() {
    char line[LINE_LEN];
    initialization(); /* Initialize the complex variables to a value of 0 + 0i */
    printf("Hi, welcome to my program :)"); /* friendly opening message */
    programStart(line); /* Start the program interaction */
    return 0;
}

/* Function to initialize all complex variables to 0 + 0i */
void initialization() {
    read_comp(&A, 0, 0);
    read_comp(&B, 0, 0);
    read_comp(&C, 0, 0);
    read_comp(&D, 0, 0);
    read_comp(&E, 0, 0);
    read_comp(&F, 0, 0);
}


void programStart(char line[]) {
    while (1) { /* Run until the stop command or the end of the file  */
        inputLine(line); /* Get user input proceed */
        fixLine(line); /* Get user input and proceed with command or errors */
    }
}

/* An array to compare the first word to the command names */
char* commandNames[NUM_FUNC] = { "read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
                                "mult_comp_img", "mult_comp_comp", "abs_comp", "stop" };

void inputLine(char line[]) {
    printf("\nPlease enter a command:\n"); /* A friendly message to the user */

    /* Check if input is available or if EOF is reached */
    if (fgets(line, LINE_LEN, stdin) == NULL) {
        printf("\nReached EOF before stop command\n");
        exit(0); /* Exit the program on EOF */
    }

    /* Print the user input */
    printf("\nThe line you entered is:\n%s", line);

}

void fixLine(char line[]) {
    int i;
    char* p, * secondNum;

    p = line;

    p = skipBlank(p); /* Skip leading spaces or tabs */

    if (p[0] == '\n') { /* Check if empty line */
        printf("(blank line)\n");
        return;
    }

    i = firstWord(p); /* Identify the command from the first word */
    if (i == -1) { /* We received undefined command */
        printf("Undefined command name\n");
        return;
    }

    p += strlen(commandNames[i]); /* Skip the command in the input (we no longer need it) */

    removeSpaces(p); /* Remove spaces after the command */

    if (p[0] == ',') { /* Check for illegal commas */
        printf("Illegal comma\n");
        return;
    }


    if (i == STOP) {
        EXTRANEOUS_TEXT(p[0])
            stop(); /* Stop the program because of stop command */
    }

    /* In all the other functions the first variable is complex (A, B, C, D, E, F) */

    MISSING_PARAMETER(p[0])

        if (!isComplex(p[0])) {
            printf("Undefined complex variable\n");
            return;
        }

    /* Here we know that p[0] is a complex */

    if (i == ABS_COMP || i == PRINT_COMP) { /* Need only one complex name for these commands */
        EXTRANEOUS_TEXT(p[1])
            if (i == ABS_COMP)
                abs_comp(sortComplex(p[0]));
            else
                print_comp(sortComplex(p[0]));

        return;
    }

    /* In all of the remaining commands we need a comma now */
    MISSING_COMMA(p[1])

        if (i == ADD_COMP || i == SUB_COMP || i == MULT_COMP_COMP) { /* Here we need two complex variables */

            if (!isComplex(p[2])) {  /* We dont have a complex variable and we will classify the error */
                MISSING_PARAMETER(p[2])

                    MULTIPLE_CONSECUTIVE_COMMAS(p[2])

                    printf("Undefined complex variable\n");
                return;
            }

            /* Here p[2] is the name of the second complex parameter (no error) */

            EXTRANEOUS_TEXT(p[3])

                /* No error all good :) */

                if (i == ADD_COMP) /* Execute the operation */
                    add_comp(sortComplex(p[0]), sortComplex(p[2]));
                else if (i == SUB_COMP)
                    sub_comp(sortComplex(p[0]), sortComplex(p[2]));
                else
                    mult_comp_comp(sortComplex(p[0]), sortComplex(p[2]));

            return;
        }

    /* The only remaning commands are: READ_COMP, MULT_COMP_REAL, MULT_COMP_IMG so we need the number for them */

    if (!isdigit(p[2])) { /* Check if the parameter is a number */
        MISSING_PARAMETER(p[2])

            MULTIPLE_CONSECUTIVE_COMMAS(p[2])

            if (p[2] != '-' || !isdigit(p[3])) { /* Check if it is a negative number */
                printf("Invalid parameter - not a number\n");
                return;
            }
    }

    /* Here we know that there is a first number */

    if (i == READ_COMP) { /* For READ_COMP, validate second number */
        secondNum = skipNum(p + 2);

        MISSING_COMMA(*secondNum)

            secondNum += 1; /* Making sure its the first digit of the number */

        if (!isdigit(secondNum[0])) { /* Checking if parameter is a number */

            MISSING_PARAMETER(secondNum[0])

                MULTIPLE_CONSECUTIVE_COMMAS(secondNum[0])

                if (secondNum[0] != '-' || !isdigit(secondNum[1])) { /* Check if negative number */
                    printf("Invalid parameter - not a number\n");
                    return;
                }

        }
        /* Here we know that there are 2 numbers in the line */

        EXTRANEOUS_TEXT(*skipNum(secondNum)) /* Check for extraneous text after the second number */

            /* Here we all good :) (no error) */
            read_comp(sortComplex(p[0]), atof(p + 2), atof(secondNum));
        return;
    }

    EXTRANEOUS_TEXT(*skipNum(p + 2))

        /* Here we all good :) (no error) */
        if (i == MULT_COMP_REAL)
            mult_comp_real(sortComplex(p[0]), atof(p + 2));
        else /* i = MULT_COMP_IMG */
            mult_comp_img(sortComplex(p[0]), atof(p + 2));

}

/* Function to print a goodbye message and exit the program */
void stop() {
    printf("You are done using the program,\nI hope you had fun :)\n"); /* goodbye message :) */
    exit(0);
}

int firstWord(char* p) {
    int i;
    int count = 0;

    for (i = 0; p[i] && p[i] != ' ' && p[i] != '\t' && p[i] != ',' && p[i] != '\n'; i++) {
        count++; /* Count characters in the first word */
    }

    for (i = 0; i < NUM_FUNC; i++) { /* Compare the first word with each of the command names */
        if (strlen(commandNames[i]) == count && !strncmp(commandNames[i], p, count)) /* If equals return i */
            return i;
    }
    return -1; /* Command name is not good return -1 */

}
/* Function to skip leading spaces or tabs */
char* skipBlank(char* s) {
    int n;
    for (n = 0; s[n] != 0 && (s[n] == ' ' || s[n] == '\t'); n++) {} /* Count how many spaces there are at the beginning of the line */
    return s + n;
}


complex* sortComplex(char x) {
    /* Function to return a pointer to the corresponding complex variable */
    if (x == 'A')
        return &A;
    if (x == 'B')
        return &B;
    if (x == 'C')
        return &C;
    if (x == 'D')
        return &D;
    if (x == 'E')
        return &E;
    if (x == 'F')
        return &F;

    return NULL; /* We will never reach this */
}
/* Function to check if a character is a valid complex variable name */
int isComplex(char x) {
    return x >= 'A' && x <= 'F'; /* Complex name can only be: A, B, C, D, E, F */
}


/* Function to remove all spaces from a given string */
void removeSpaces(char* str) {
    int i;
    /* Counter for non space character */
    int count = 0;

    /* Traverse the given string. If current character
     is not space, then place it at index 'count++' */
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            str[count++] = str[i]; /* Index is not a space, we add it to the array an updating 'count' */
    }

    str[count] = '\0'; /* Adding null to the end of the “string” array */
}

char* skipNum(char* s) {
    int i = 0;
    int dot = 0; /* Flag to check if we've encountered a decimal point */

    if (s[0] == '-')
        i++; /* If the number starts with a negative sign, skip it */

    for (; isdigit(s[i]) || s[i] == '.'; i++) { /* Loop through the string while the current character is a digit or a dot */
        if (s[i] == '.') {
            if (dot || !isdigit(s[i + 1])) /* Check if dot is in the end of the number or if we saw a dot before -dot is not valid (also end of a number)*/
                return s + i; /* Return a pointer to the char after the number */
            dot = 1; /* Set the flag to indicate that we've seen one dot */
        }
    }
    return s + i; /* Return a pointer to the char after the number */

}


