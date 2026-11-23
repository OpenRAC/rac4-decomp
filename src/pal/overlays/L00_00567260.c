#include "common.h"

s32 func_L00_00567260(s32 id)
{
    if (id == -507)
        goto value127;
    if (id < -506) {
        if (id == -511)
            goto value111;
        if (id < -510) {
            if (id == -514)
                goto value118;
            if (id < -514)
                goto missing;
            return 22;
        }
        if (id == -509)
            goto value110;
        if (id < -508)
            return 104;
        goto value128;
    }
    if (id == -503)
        goto value115;
    if (id < -502) {
        if (id < -504)
            goto value125;
        return 12;
    }
    if (id == -501)
        goto value113;
    if (id < -501)
        goto value16;
    if (id == -500)
        goto value116;
    if (id != 0)
        goto missing;
    return 0;
value116:
    return 116;
value113:
    return 113;
value16:
    return 16;
value115:
    return 115;
value125:
    return 125;
value127:
    return 127;
value128:
    return 128;
value110:
    return 110;
value111:
    return 111;
value118:
    return 118;
missing:
    return -1;
}
