#include "common.h"

int D_00221188 = 0;
char *D_00221184 = 0;
extern char *D_0023AC20[];
/* Initialize and return the derived memory base. */
void *func_00438400(void)
{
    if (!D_00221188) {
        D_00221184 = D_0023AC20[0] + 0x900000;
        D_00221188 = 1;
    }
    return D_00221184;
}
