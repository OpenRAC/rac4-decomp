#include "common.h"
typedef struct {
    int f0, f4, f8, fC;
} Entry;
extern Entry D_00328548[];
int func_004EB588(int a, int b)
{
    int i;
    int result = 1;
    for (i = 0; i < 32; i++) {
        if (D_00328548[i].f4 == a && D_00328548[i].f0 == b) {
            result = 0;
            break;
        }
    }
    return result;
}
