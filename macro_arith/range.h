/* range.h: define range for metaprogramming */

#ifndef __RANGE_H__
#define __RANGE_H__

#include "arith.h"

#define OUTPUT_RANGE_VAL(x) x,

#define RANGE_INDIRECT() RANGE_

#define RANGE_NO_EVAL(start, end, step) \
    RANGE_(start, end, step) end

#define RANGE_(start, end, step) \
    IF( IS_NOT_ZERO( SUB(end, start) ) ) ( \
        OUTPUT_RANGE_VAL(start) \
        DEFER2(RANGE_INDIRECT) () (ADD(start, step), end, step) \
    )

#define RANGE(start, end, step) \
    EXPAND(RANGE_NO_EVAL(start, end, step))

#endif /* __RANGE_H__ */
