#include <stdlib.h>
#include <stdio.h>

/**
 * @brief recursively calculates the factorial of an integer n.
 * 
 * @param n number to find factorial of.
 * @return int n factorial.
 */
int factorial(int n) {
  // the base case - this determines when the recursion should stop
  if (n == 0) {
    return 1;
  }

  return n * factorial(n - 1);
}

int main(int argc, char **argv) {
  /*
  The program should accept a command line argument as follows:
  ./combinatorials n C r
  ./combinatorials n P r
  
  where n and r are both positive integers, and r is always less than or equal to n.

  for example:
  ./combinatorials 7 C 2

  Your program should then calculate and print out the correct result

  nCr should return the total combinations of r items out of n.
  This is calculated by: n! / (r! (n - r)!)

  nPr should return the total permutations of r items out of n.
  This is calculated by: n! / (n-r)!

  Add appropriate validation to your program to make your code robust.

  You should try and use functions to write your program.

  */

  int result;

  if (argc == 4) {
    int n;
    int r;
    int x;
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%c", &x);
    sscanf(argv[3], "%d", &r);

    int n_fac = factorial(n);
    int r_fac = factorial(r);
    int q_fac = factorial((n - r));
    switch(x){
      case 'P':
        result = n_fac / q_fac;
      break;

      case 'C':
        result = n_fac / (r_fac * q_fac);
      break;
    }
  }
  printf("Result = %i\n", result);

  return 0;
}