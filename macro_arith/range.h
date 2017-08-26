/* range.h: define range for meta-programming */

#ifndef __RANGE_H__
#define __RANGE_H__

#include "arith.h"

/* defines the max number of iteration */
#define RANGE_EXPAND1(...) __VA_ARGS__
#define RANGE_EXPAND2(...) RANGE_EXPAND1(__VA_ARGS__)
#define RANGE_EXPAND3(...) RANGE_EXPAND2(__VA_ARGS__)
#define RANGE_EXPAND4(...) RANGE_EXPAND3(__VA_ARGS__)
#define RANGE_EXPAND5(...) RANGE_EXPAND4(__VA_ARGS__)
#define RANGE_EXPAND6(...) RANGE_EXPAND5(__VA_ARGS__)
#define RANGE_EXPAND7(...) RANGE_EXPAND6(__VA_ARGS__)
#define RANGE_EXPAND8(...) RANGE_EXPAND7(__VA_ARGS__)
#define RANGE_EXPAND9(...) RANGE_EXPAND8(__VA_ARGS__)
#define RANGE_EXPAND10(...) RANGE_EXPAND9(__VA_ARGS__)
#define RANGE_EXPAND11(...) RANGE_EXPAND10(__VA_ARGS__)
#define RANGE_EXPAND12(...) RANGE_EXPAND11(__VA_ARGS__)
#define RANGE_EXPAND13(...) RANGE_EXPAND12(__VA_ARGS__)
#define RANGE_EXPAND14(...) RANGE_EXPAND13(__VA_ARGS__)
#define RANGE_EXPAND15(...) RANGE_EXPAND14(__VA_ARGS__)
#define RANGE_EXPAND16(...) RANGE_EXPAND15(__VA_ARGS__)
#define RANGE_EXPAND17(...) RANGE_EXPAND16(__VA_ARGS__)
#define RANGE_EXPAND18(...) RANGE_EXPAND17(__VA_ARGS__)
#define RANGE_EXPAND19(...) RANGE_EXPAND18(__VA_ARGS__)
#define RANGE_EXPAND20(...) RANGE_EXPAND19(__VA_ARGS__)
#define RANGE_EXPAND21(...) RANGE_EXPAND20(__VA_ARGS__)
#define RANGE_EXPAND22(...) RANGE_EXPAND21(__VA_ARGS__)
#define RANGE_EXPAND23(...) RANGE_EXPAND22(__VA_ARGS__)
#define RANGE_EXPAND24(...) RANGE_EXPAND23(__VA_ARGS__)
#define RANGE_EXPAND25(...) RANGE_EXPAND24(__VA_ARGS__)
#define RANGE_EXPAND(...) RANGE_EXPAND25(__VA_ARGS__)

#define OUTPUT_RANGE_VAL(x) x,

#define RANGE_INDIRECT() RANGE_

#define RANGE_NO_EVAL(start, end, step) RANGE_(start, end, step) end

#define RANGE_(start, end, step) \
    IF( IS_NOT_ZERO( SUB(end, start) ) ) ( \
        OUTPUT_RANGE_VAL(start) \
        DEFER2(RANGE_INDIRECT) () (ADD(start, step), end, step) \
    )

#define RANGE(start, end, step) RANGE_EXPAND(RANGE_NO_EVAL(start, end, step))

#endif /* __RANGE_H__ */
