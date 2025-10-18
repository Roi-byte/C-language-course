
#include "header.h"

/* The main method: */
int main() {
    adjmat mat; /* Declare the adjmat matrix */
    int input1, input2; /* Variables to store user input */

    /* Welcome message and inform the user about the number of nodes */
    printf("Hello, welcome to my program, \nPlease be aware that the number of nodes in the tree is N = %d\n", N);

    /* Create the adjmat matrix based on user input */
    create_mat(mat);

    /* Print the adjmat matrix entered by the user */
    printf("\nThe matrix you entered is:\n");
    print_mat(mat);

    /* Prompt the user to enter pairs of indexes */
    printf("\nPlease enter two indexes, enter -1 -1 in order to stop the program\n");

    /* Loop to process user inputs until -1 -1 is entered */
    while (scanf("%d%d", &input1, &input2) == 2 && !(input1 == -1 && input2 == -1)) {
        /* Print the user inputs and check if a path exists between them */
        printf("\nThe first index you entered is %d\nThe second index you entered is %d\nThe result is %d\n", input1, input2, path(mat, input1, input2));
        printf("\nPlease enter two indexes again, enter -1,-1 in order to stop the program\n");
    }

    /* Exit message */
    printf("\nYou are done using the program,\nI hope you had fun :)\n");
    return 0;
}

/* Function to check if a path exists from node u to node v */
int path(adjmat mat, int u, int v) {
    int father; /* Variable to track the parent of a node */

    /* Return FALSE if either node index is out of bounds */
    if (u < 0 || v < 0 || u >= N || v >= N)
        return FALSE;

    /* Traverse the tree upward from v to check if u is an ancestor */
    for (father = v; father != -1; father = find_father(mat, father)) {
        if (u == father) /* Found a path from v to u */
            return TRUE;
    }
    return FALSE; /* No path found */
}

/* Function to find the parent of a given node */
int find_father(adjmat mat, int node) {
    int i;
    /* Loop through the matrix to find the parent of the node */
    for (i = 0; i < N; i++) {
        if (mat[i][node]) /* Return parent found */
            return i;
    }
    return -1; /* Node has no parent */
}

/* Function to print the adjmat matrix */
void print_mat(adjmat mat) {
    int i, j;
    /* Loop through the matrix rows and columns */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", mat[i][j]); /* Print the matrix value */
            if (j != N - 1) /* Add a tab except for the last column */
                printf("\t");
            else /* Add a newline at the end of each row */
                printf("\n");
        }
    }
}

/* Function to create the adjmat matrix from user input */
void create_mat(adjmat mat) {
    int i, j;
    /* Prompt the user to enter values for the matrix */
    printf("\nPlease enter values for the %d*%d adjmat matrix, enter only values of 1 or 0:\n", N, N);

    /* Populate the matrix with user input */
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

