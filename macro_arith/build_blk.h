/* build_blk.h: defines boilerplates for macro arithmetics */

#ifndef __BUILD_BLK_H__
#define __BUILD_BLK_H__

/* EXPAND and DEFER */
#define EMPTY()

#define DEFER(id) id EMPTY()
#define DEFER2(id) id DEFER(EMPTY) ()
#define DEFER3(id) id DEFER2(EMPTY) ()
#define DEFER4(id) id DEFER3(EMPTY) ()
#define DEFER5(id) id DEFER4(EMPTY) ()
#define DEFER6(id) id DEFER5(EMPTY) ()
#define DEFER7(id) id DEFER6(EMPTY) ()

#include "expand.h"

/* define generic recursion limits */
#define EVAL(...)  EVAL1(EVAL1(EVAL1(__VA_ARGS__)))
#define EVAL1(...) EVAL2(EVAL2(EVAL2(__VA_ARGS__)))
#define EVAL2(...) EVAL3(EVAL3(EVAL3(__VA_ARGS__)))
#define EVAL3(...) EVAL4(EVAL4(EVAL4(__VA_ARGS__)))
#define EVAL4(...) EVAL5(EVAL5(EVAL5(__VA_ARGS__)))
#define EVAL5(...) __VA_ARGS__

/* probe */
#define SECOND(a, b, ...) b
#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1

/* not */
#define NOT(x) IS_PROBE(CAT(_NOT_, x))
#define _NOT_0 PROBE()

/* complement */
#define COMPL(x) CAT(COMPL_, x)
#define COMPL_0 1
#define COMPL_1 0

/* boolean */
#define BOOL(x) NOT(NOT(x))

/* if-statement: false_clause is optional */
#define IF(cond) IIF(BOOL(cond))
#define IIF_1(true_clause, ...) true_clause
#define IIF_0(true_clause, ...) __VA_ARGS__
#define IIF(bit) CAT(IIF_, bit)

/* replace arguments */
#define EAT(...)

/* test if the value is an existing macro */
#define EXPAND_TEST_EXISTS(...) EXPAND, EXISTS(__VA_ARGS__) ) EAT (
#define GET_TEST_EXISTS_RESULT(x) ( CAT(EXPAND_TEST_, x), DOESNT_EXIST )

/* extract the 2nd field in the tuple */
#define GET_TEST_EXIST_VALUE_(expansion, exist_value) exist_value
#define GET_TEST_EXIST_VALUE(x) GET_TEST_EXIST_VALUE_ x
#define TEST_EXISTS(x) \
    EXPAND1(DEFER(GET_TEST_EXIST_VALUE_) GET_TEST_EXISTS_RESULT(x))

/* return 1 if exists, otherwise 0 */
#define DOES_VALUE_EXIST_EXISTS(...) 1
#define DOES_VALUE_EXIST_DOESNT_EXIST 0
#define DOES_VALUE_EXIST(x) CAT(DOES_VALUE_EXIST_, x)

/* extract x from EXIST(x) */
#define EXTRACT_VALUE_EXISTS(...) __VA_ARGS__
#define EXTRACT_VALUE(value) CAT(EXTRACT_VALUE_, value)

/* extract value if exists, otherwise return given default value */
#define TRY_EXTRACT_EXISTS(value, ...) \
    IF( DOES_VALUE_EXIST(TEST_EXISTS(value)) ) \
        (EXTRACT_VALUE(value), __VA_ARGS__)

/* boolean operations */
#define OR_00 EXISTS(0)
#define OR(x, y) TRY_EXTRACT_EXISTS ( CAT(CAT(OR_, x), y), 1 )

#define XOR_01 EXISTS(1)
#define XOR_10 EXISTS(1)
#define XOR(x, y) TRY_EXTRACT_EXISTS ( CAT(CAT(XOR_, x), y), 0)

#define IS_ZERO_0 EXISTS(1)
#define IS_ZERO(x) TRY_EXTRACT_EXISTS ( CAT(IS_ZERO_, x), 0)

#define IS_NOT_ZERO(x) NOT(IS_ZERO(x)) 

/* test if arguments is enclosed in parentheses */
#define IS_ENCLOSE_TEST(...) EXISTS(1)
#define IS_ENCLOSED(x, ...) TRY_EXTRACT_EXISTS ( IS_ENCLOSE_TEST x, 0 )

#define ENCLOSE_EXPAND(...) EXPANDED, ENCLOSED, (__VA_ARGS__) ) EAT (
#define GET_CAT_EXP(a, b) (a, ENCLOSE_EXPAND b, DEFAULT, b)

/* different flavors of CAT */
#define CAT_WITH_ENCLOSED(a, b) a b
#define CAT_WITH_DEFAULT(a, b) a ## b
#define CAT_WITH(a, _, f, b) CAT_WITH_ ## f (a, b)

/* defer call to CAT_WITH until args are evaluated */
#define EXPAND_CAT_WITH(...) CAT_WITH __VA_ARGS__

#define PRIMITIVE_CAT(x, y) x ## y
#define CAT(a, b) EXPAND_CAT_WITH ( GET_CAT_EXP(a, b) )

#endif /* __BUILD_BLK_H__ */
