#ifndef __BINOMINAL_H__
#define __BINOMINAL_H__

#include "macro_arith/arith.h"

/* for macro function that uses loop/recursion,
 * we should define a separate expand for it.
 *
 * For BINOM(n, k), BINOM_EXPAND defines max k
 */
#define BINOM_EXPAND1(...) __VA_ARGS__
#define BINOM_EXPAND2(...) BINOM_EXPAND1(__VA_ARGS__)
#define BINOM_EXPAND3(...) BINOM_EXPAND2(__VA_ARGS__)
#define BINOM_EXPAND4(...) BINOM_EXPAND3(__VA_ARGS__)
#define BINOM_EXPAND5(...) BINOM_EXPAND4(__VA_ARGS__)
#define BINOM_EXPAND(...) BINOM_EXPAND5(__VA_ARGS__)

#define BINOM_NO_EVAL(n, k, numer, denom) \
    IF (IS_NOT_ZERO(k)) \
    (\
        DEFER2(BINOM_INDIRECT) () \
        ( \
            DEC(n), DEC(k), MUL(numer, n), MUL(denom, k) \
        ) \
        , \
        DIV(numer, denom) \
    )
#define BINOM_INDIRECT() BINOM_NO_EVAL
#define BINOM(n, k) BINOM_EXPAND(BINOM_NO_EVAL(n, k, 1, 1))

#endif /* __BINOMINAL_H__ */
