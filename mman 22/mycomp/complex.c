#include "complex.h"

void read_comp(complex *a, double real, double image) {
    a->real = real; /* Assign the real part to the complex structure */
    a->image = image; /* Assign the imaginary part to the complex structure */
}


void print_comp(complex *a) {
    printf("%f", a->real); /* Print the real part */
    if (a->image >= 0)
        printf(" + (%f)i\n", a->image);  /* If the imaginary part is non-negative, print with a '+' sign */
    else
        printf(" - (%f)i\n", -a->image); /* If the imaginary part is negative, print with a '-' sign */
    
}


void add_comp(complex *a, complex *b) {
    complex tmp; /* Temporary complex structure to hold the result */
    
    tmp.real = a->real + b->real; /* Add the real parts */
    tmp.image = a->image + b->image; /* Add the imaginary parts */
    
    print_comp(&tmp); /* Print the resulting complex number */
    
}


void sub_comp(complex *a, complex *b) {
    complex tmp; /* Temporary complex structure to hold the result */
    
    tmp.real = a->real - b->real; /* Subtract the real parts */
    tmp.image = a->image - b->image; /* Subtract the imaginary parts */
    
    print_comp(&tmp); /* Print the resulting complex number */
    
}


void mult_comp_real(complex *a, double num) {
    complex tmp; /* Temporary complex structure to hold the result */
    
    tmp.real = a->real * num; /* Multiply the real part of the complex number by the real number */
    tmp.image = a->image * num; /* Multiply the imaginary part of the complex number by the real number */
    
    print_comp(&tmp); /* Print the resulting complex number */
}


void mult_comp_img(complex *a, double img) {
    complex tmp; /* Temporary complex structure to hold the result */
    
    tmp.real = -img * (a->image); /* Calculate the real part of the result */
    tmp.image = img * a->real; /* Calculate the imaginary part of the result */
    
    print_comp(&tmp); /* Print the resulting complex number */
}


void mult_comp_comp(complex *a, complex *b) {
    complex tmp; /* Temporary complex structure to hold the result */
    
    tmp.real = (a->real * b->real) - (a->image * b->image); /* Calculate the real part of the result using the formula provided */
    tmp.image = (a->real * b->image) + (a->image * b->real); /* Calculate the imaginary part of the result using the formula provided */
    
    print_comp(&tmp); /* Print the resulting complex number */
}


void abs_comp(complex *a) {
    printf("%f\n", sqrt(a->real * a->real + a->image * a->image)); /* Calculating absolute value and printing the result */
}





