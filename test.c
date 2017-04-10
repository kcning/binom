/* test.c: show usage of BINOM(n, k) */

#include <stdio.h>

#include "binominal.h"

int
main(int argc, char* argv[]) {
    printf("choose 2 from 100 is: %d\n", BINOM(100, 2));
    printf("choose 3 from 6 is: %d\n", BINOM(6, 3));
    printf("choose 0 from 4 is: %d\n", BINOM(4, 0));

    return 0;
}
