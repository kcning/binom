/* foreach.h: define foreach for meta-programming */

#ifndef __FOREACH_H__
#define __FOREACH_H__

#include "list.h"

/* 1D */
#define FOR_EACH_INDIRECT() FOR_EACH_NO_EVAL

#define FOR_EACH_NO_EVAL(op, ...) \
    IF ( LIST_IS_NOT_EMPTY(__VA_ARGS__) ) ( \
        DEFER(op) ( OPT_REM_ENCLOSE ( LIST_HEAD(__VA_ARGS__) ) ) \
        DEFER2(FOR_EACH_INDIRECT) () (op, LIST_TAIL(__VA_ARGS__)) \
    )

#define FOR_EACH(op, ...) \
    EXPAND(FOR_EACH_NO_EVAL(op, __VA_ARGS__))


/* 2D */
#define FOR_EACH_2D_INDIRECT() FOR_EACH_2D_

#define FOR_EACH_2D_(op, list1, ori_list1, list2, ori_list2) \
    IF ( LIST_IS_NOT_EMPTY list2 ) ( \
        op ( LIST_HEAD list1 , LIST_HEAD list2 ) \
        DEFER2(FOR_EACH_2D_INDIRECT) () \
            (op, list1, list1, (LIST_TAIL list2), ori_list2) \
        , \
        IF ( LIST_IS_NOT_EMPTY(LIST_TAIL list1) ) ( \
            DEFER3(FOR_EACH_2D_INDIRECT) () \
                (op, (LIST_TAIL ori_list1), (LIST_TAIL ori_list1), ori_list2, ori_list2) \
        ) \
    )

#define FOR_EACH_2D_NO_EVAL(op, list1, list2) \
    FOR_EACH_2D_(op, list1, list1, list2, list2)

#define FOR_EACH_2D(op, list1, list2) \
    EXPAND(FOR_EACH_2D_NO_EVAL(op, list1, list2))

/* 3D */
#define FOR_EACH_3D_INDIRECT() FOR_EACH_3D_

#define FOR_EACH_3D_(op, list1, ori_list1, list2, ori_list2, list3, ori_list3) \
    IF ( LIST_IS_NOT_EMPTY list3 ) ( \
        op (LIST_HEAD list1, LIST_HEAD list2, LIST_HEAD list3) \
        DEFER2(FOR_EACH_3D_INDIRECT)() \
            (op, list1, list1, list2, list2, (LIST_TAIL list3), ori_list3) \
        , \
        IF ( LIST_IS_NOT_EMPTY (LIST_TAIL list2) ) ( \
            DEFER3(FOR_EACH_3D_INDIRECT)() \
                (op, ori_list1, ori_list1, \
                    (LIST_TAIL ori_list2), (LIST_TAIL ori_list2), ori_list3, ori_list3) \
            IF ( LIST_IS_NOT_EMPTY( LIST_TAIL list1) ) ( \
                DEFER4(FOR_EACH_3D_INDIRECT)() \
                    (op, (LIST_TAIL ori_list1), (LIST_TAIL ori_list1), \
                        ori_list2, ori_list2, ori_list3, ori_list3) \
            ) \
        ) \
    )

#define FOR_EACH_3D_NO_EVAL(op, list1, list2, list3) \
    FOR_EACH_3D_(op, list1, list1, list2, list2, list3, list3)

#define FOR_EACH_3D(op, list1, list2, list3) \
    EXPAND(FOR_EACH_3D_NO_EVAL(op, list1, list2, list3))


#endif /* __FOREACH_H__ */
