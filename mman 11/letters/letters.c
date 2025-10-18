

#include <stdio.h>
#include <ctype.h>  

/* Define states for the finite state machine */
enum status {OUT, IN_STRING};

void main(void) {
    int character; /* variable to store the current character */
    int state = OUT; /* current state, initially OUT (not inside a string) */
    int capitalize_next = 1;  /* flag to determine if the next letter should be capitalized */

    /* read input one character at a time until EOF */
    while ((character = getchar()) != EOF) {
        /* skip digits entirely */
        if (isdigit(character)) {
            continue;  
        }

        /* handle behavior based on the current state */
        switch (state) {
            case OUT: /* outside a quoted string */
                if (character == '\"') { /* if a double quote is encountered */
                    state = IN_STRING;  /* switch to IN_STRING state */
                    putchar(character);  /* print the quote */
                    continue;  /* skip further processing for this character */
                }

                /* capitalize the first letter after a period */
                if (capitalize_next && isalpha(character)) {
                    character = toupper(character);  /* convert to uppercase */
                    capitalize_next = 0;  /* reset the capitalize flag */
                } 
                /* convert all other letters to lowercase */
                else if (!capitalize_next && isupper(character)) {
                    character = tolower(character);  
                }

                /* reset the capitalize flag after a period */
                if (character == '.') {  
                    capitalize_next = 1;  
                }

                putchar(character);  /* print the processed character */
                break;

            case IN_STRING: /* inside a quoted string */
                if (character == '\"') { /* if a closing quote is encountered */
                    state = OUT;  /* switch back to OUT state */
                }
                character = toupper(character);  /* convert all characters in the string to uppercase */
                putchar(character);  /* print the processed character */
                break;
        }
    }
}
