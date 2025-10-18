
#include <stdio.h>

#define TRUE 1 /* Macro to represent a true value */
#define FALSE 0 /* Macro to represent a false value */
#define N 5 /* Number of nodes in the tree */
typedef int adjmat[N][N]; /* Define adjmat as a 2D array of size N x N */

void create_mat(adjmat mat); /* A method that receives an empty adjmat matrix and puts values from the user in it */

void print_mat(adjmat mat); /* A method that receives an adjmat matrix and prints it */

int path(adjmat mat, int u, int v); /* A method that takes an adjacency matrix (adjmat) and two indexes, u and v. 
   				    It returns 1 (TRUE) if u is an ancestor of v in the tree, and 0 (FALSE) otherwise.
  			            If u equals v, it returns TRUE, and if either of the indexes is out of bounds (not in the tree), it returns FALSE. */


int find_father(adjmat mat, int node); /* A method that takes an adjacency matrix (adjmat) and a node index.
   					It loops through the matrix to find the parent of the given node.
   					If a parent is found, it returns the index of the parent node.
  					If no parent is found (i.e., the node is the root), it returns -1. */

