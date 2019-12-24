#ifndef LIBASM_TEST_H
#define LIBASM_TEST_H

#include <stdio.h>

/**
 * @brief Assert that a value is true and print it to stderr
 * @param val the value or expression to assert
 */
#define ASSERT(val) \
    { \
        fflush(stdout);\
        fflush(stderr);\
        if (!(val)) \
        { \
            fprintf(stderr, "Assert failed: %s\n", #val); \
            return 1;\
        } \
        else fprintf(stderr, "Assert succeeded: %s\n", #val); \
    }

#endif //LIBASM_TEST_H
