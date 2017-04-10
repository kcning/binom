/* arith.h: define macro arith */

#ifndef __ARITH_H__
#define __ARITH_H__

#include "build_blk.h"
#include "arith_table.h"

/* increment and decrement */
#define INC(x) PRIMITIVE_CAT(INC_, x)
#define DEC(x) PRIMITIVE_CAT(DEC_, x)

/* add */
#define ADD_INDIRECT() ADD_NO_EVAL
#define ADD_NO_EVAL(a, b) \
    IF ( IS_NOT_ZERO(b) ) ( \
        DEFER2(ADD_INDIRECT) () (INC(a), DEC(b)) \
        , \
        a \
    )
#define ADD(a, b) EVAL(ADD_NO_EVAL(a, b))

/* substract */
#define SUB_INDIRECT() SUB_NO_EVAL
#define SUB_NO_EVAL(a, b) \
    IF ( IS_NOT_ZERO(b) ) ( \
        DEFER2(SUB_INDIRECT) () (DEC(a), DEC(b)) \
        , \
        a \
    )
#define SUB(a, b) EVAL(SUB_NO_EVAL(a, b))

/* multiply */
#define MUL_(a, count, sum) \
    IF (IS_NOT_ZERO(count)) \
    ( \
        DEFER2(MUL_INDIRECT) () \
        ( \
            a, DEC(count), ADD(sum, a) \
        ) \
        ,\
        sum \
    )
#define MUL_INDIRECT() MUL_
#define MUL(a, b) EXPAND(MUL_(a, b, 0))

/* division */
#define DIV_(a, b, q, rem) \
    IF (IS_NOT_ZERO(rem)) \
    ( \
        DEFER2(DIV_INDIRECT) () \
        ( \
            a, b, INC(q), SUB(rem, b) \
        ) \
        ,\
        q \
    )
#define DIV_INDIRECT() DIV_
#define DIV(a, b) EXPAND(DIV_(a, b, 0, a))  /* EXPAND defines quotient range */

#endif  /* __ARITH_H__ */
