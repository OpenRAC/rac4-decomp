#include "common.h"

s64 D_00222260 = 0;
s64 D_00222268 = 0;
s64 D_00222270 = 0;

/* Look up a small record by id, storing its size. */
void *func_L01_004DAB58(void *arg0, s32 id, s32 *size) {
    void *p = 0;

    switch (id) {
    case 0x04027571:
        p = &D_00222260;
        *size = 4;
        break;
    case 0x04027572:
        p = &D_00222268;
        *size = 4;
        break;
    case 7:
        p = &D_00222270;
        *size = 0xC;
        break;
    }
    return p;
}
