/* list.h: define list for metaprogramming */

#ifndef __LIST_H__
#define __LIST_H__

#include "arith.h"

/* list */
#define LIST_HEAD(x, ...) x
#define LIST_TAIL(x, ...) __VA_ARGS__

#define TEST_LAST EXISTS(1)

#define LIST_IS_EMPTY(...) \
    TRY_EXTRACT_EXISTS( \
        DEFER(LIST_HEAD) (__VA_ARGS__ EXISTS(1)) \
        , \
        0 \
    )

#define LIST_IS_NOT_EMPTY(...) \
    NOT(LIST_IS_EMPTY(__VA_ARGS__))

/* tuples */
#define ENCLOSE(...) ( __VA_ARGS__ )
#define REM_ENCLOSE_(...) __VA_ARGS__
#define REM_ENCLOSE(...) REM_ENCLOSE_ __VA_ARGS__

#define IF_ENCLOSED_1(true, ...) true
#define IF_ENCLOSED_0(true, ...) __VA_ARGS__
#define IF_ENCLOSED(...) CAT(IF_ENCLOSED_, IS_ENCLOSED(__VA_ARGS__))

#define OPT_REM_ENCLOSE(...) \
    IF_ENCLOSED (__VA_ARGS__) ( REM_ENCLOSE(__VA_ARGS__), __VA_ARGS__)

#endif /* __LIST_H__ */
