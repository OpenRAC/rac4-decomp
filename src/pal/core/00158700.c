#include "common.h"
extern s64 func_00158C70(int, int, void *, int, int);
/* Packages three words for the shared operation. */
s64 func_00158700(int a, int b, int c) {
    int values[3];
    values[0] = a;
    values[2] = c;
    values[1] = b;
    return func_00158C70(78, 12, values, 0, 0);
}
