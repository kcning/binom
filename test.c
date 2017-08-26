/* test.c: show usage of metaprogramming with C macro */

#include <stdio.h>

#include "binominal.h"
#include "macro_arith/range.h"
#include "macro_arith/foreach.h"


#define LAST_ELEMENT       25

/* DO NOT wrap those with do-while */
#define PRINT_CALL(x) \
    printf("%d\n", x);

#define INIT_CALL(type, x, val) \
    type x = val;

#define ASSIGN_CALL(x, val) \
    x = val;

#define UPDATE_PRINT_CALL(x, val) \
    printf("%d\n", x = val);


int
main(int argc, char* argv[]) {
    printf("choose 3 from 6 is: %d\n", BINOM(6, 3));
    printf("choose 0 from 4 is: %d\n", BINOM(4, 0));

    int arr[LAST_ELEMENT + 1] = { RANGE(0, LAST_ELEMENT, 1) };

    printf("array: ");
    for(int i = 0; i < LAST_ELEMENT+1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("testing FOR_EACH:\n");
    printf("printing range 1 ~ 10:\n");
    FOR_EACH(PRINT_CALL, RANGE(1, 10, 1))

    printf("creating variables i, j, k, l:\n");
    FOR_EACH(INIT_CALL, (int, i, 2), (int, j, 3), (int, k, 4), (int, l, 5) );
    printf("printing variables i, j, k, l:\n");
    FOR_EACH(PRINT_CALL, i, j, k, l);

    printf("testing FOR_EACH_2D:\n");
    FOR_EACH_2D(ASSIGN_CALL, (i, j, k, l), (100));
    printf("printing variables new values for i, j, k, l:\n");
    FOR_EACH(PRINT_CALL, i, j, k, l);
    FOR_EACH_2D(UPDATE_PRINT_CALL, (i, j, k, l), (RANGE(200, 204, 1)))

    printf("testing FOR_EACH_3D:\n");
    FOR_EACH_3D(INIT_CALL, (float), (max, min), (0))
    printf("max = %f\n", max);
    printf("min = %f\n", min);

    return 0;
}
