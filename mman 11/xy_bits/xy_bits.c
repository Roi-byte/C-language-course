#include <stdio.h>



/* Function Prototypes */
/* Prints the binary representation of an unsigned long integer */
void print_binary(unsigned long num);

/* Calculates the number of bits in an unsigned long integer dynamically */
unsigned long int size_int(void);

/* Checks if the 7th bit (from the right) is set in the given number */
int bit7_check(unsigned long int y);

/* Checks and corrects the 12th bit of the given number x */
void x_correction(unsigned long x);

/* Main Function */
int main() {
    unsigned long int x, y;

    /* Prompt the user to enter two unsigned long integer variables */
    printf("Hi, welcome to my program,\nplease enter two unsigned int variables x, y: ");
    scanf("%lu %lu", &x, &y);

    /* Print the entered values */
    printf("\nThe numbers you entered are: %lu and %lu\n", x, y);

    /* Print the binary representation of x */
    printf("The binary representation of x is: ");
    print_binary(x);

    /* Print the binary representation of y */
    printf("The binary representation of y is: ");
    print_binary(y);

    /* Check if the 7th bit of y (6th index) is set and output the result */
    if (bit7_check(y)) {
        printf("In variable y, bit number six is ON\n");
    } else {
        printf("In variable y, bit number six is not ON\n");
    }

    /* Check and correct the 12th bit of x if necessary */
    x_correction(x);

    return 0;
}

/* Function to print the binary representation of an unsigned long integer */
void print_binary(unsigned long num) {
    /* Determine the number of bits in an unsigned long integer using size_int() function */
    unsigned long size_bits = size_int();
    int i;

    /* Print the binary representation for 64-bit systems */
    if (size_bits == 64) {
        for (i = 63; i >= 0; i--) {
            /* Extract and print each bit */
            int bit = (num >> i) & 1;
            printf("%d", bit);
        }
    } else { 
        /* Print the binary representation for 32-bit systems */
        for (i = 31; i >= 0; i--) {
            /* Extract and print each bit */
            int bit = (num >> i) & 1;
            printf("%d", bit);
        }
    }
    /* Add a newline after printing the binary representation */
    printf("\n");
}

/* Function to calculate the number of bits in an unsigned long integer */
unsigned long int size_int(void) {
    unsigned long int count, size = -1;

    /* Loop through bits, right-shifting until the size becomes 0 */
    for (count = 0; size; size >>= 1, count++);
    return count; 
}

/* Function to check if the 7th bit (from the right) is set */
int bit7_check(unsigned long int y) {
    /* Shift y right by 6 positions and check the least significant bit */
    if ((y >> 6) & 1) {
        return 1; /* Return 1 if the bit is set */
    } else {
        return 0; /* Return 0 if the bit is not set */
    }
}

/* Function to correct x by turning on the 12th bit if not already set */
void x_correction(unsigned long x) {
    /* Check if the 12th bit is already set */
    if ((x >> 12) & 1) {
        /* If the 12th bit is set, print x without modification */
        printf("The binary representation of x after correction is still: ");
        print_binary(x);
    } else {
        /* If the 12th bit is not set, turn it on and print the updated x */
        printf("The binary representation of x after turning bit 12 on is: ");
        x = x + 4096;  /* Add 2^12 (4096) to turn on the 12th bit */
        print_binary(x);
    }
}




