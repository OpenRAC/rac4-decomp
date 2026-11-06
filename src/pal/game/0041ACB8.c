#include "common.h"
typedef struct {
    short indices[64];
} List;
extern List D_0026FB38[];
extern char *D_002214F4;
void *func_0041ACB8(int a, int b)
{
    int i;
    for (i = 1; i <= D_0026FB38[a].indices[0]; i++) {
        char *obj = D_002214F4 + D_0026FB38[a].indices[i] * 256;
        char *q = *(char **)(obj + 0xAC);
        if (q && *(short *)(q + 0xC2) == b)
            return obj;
    }
    return 0;
}
