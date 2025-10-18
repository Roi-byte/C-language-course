#include <stdio.h>
#include <math.h>

/* the struct for a complex number */
typedef struct complex {
    double real;
    double image;
} complex;

/*A function that places values in a complex variable*/
void read_comp(complex *a, double real, double image);

/*A function that prints a complex number*/
void print_comp(complex *a);

/*A function that receives two complex numbers, sums them and prints the result*/
void add_comp(complex *a, complex *b);

/*A function that receives two complex numbers, subtracts them and prints the result*/
void sub_comp(complex *a, complex *b);

/*A function that calculates the multiplication of a complex number and a real number received and prints the result*/
void mult_comp_real(complex *a, double num);

/*A function that calculates the multiplication of a complex number and an imaginary number received and prints the result*/
void mult_comp_img(complex *a, double img);

/*A function that calculates the multiplication of two complex numbers received and prints the result*/
void mult_comp_comp(complex *a, complex *b);

/*A function that calculates the absolute value of the complex number received and prints the result*/
void abs_comp(complex *a);



