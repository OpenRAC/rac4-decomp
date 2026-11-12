/* Not matching yet: SIZE ours 156 / retail 164 (tools/try_func.py func_L01_004CA294 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 key;
    s32 value;
} Entry;

extern Entry D_003AB2E0[];

s32 func_L01_004CA294(s32 arg0, u8 *arg1, s32 arg2, u8 *arg3) {
    s32 index;
    s32 result;
    s32 skey;
    u16 value;
    s32 *keys;
    s32 *vals;
    Entry *p;

    keys = (s32 *)(arg3 + 0x20);
    value = *(u16 *)(arg1 + 0xBC);
    if (*(u8 *)(arg3 + 0x64) != 0) {
        skey = (s16)value;
        index = 0;
        p = D_003AB2E0;
        do {
            if (p->key == skey) {
                result = p->value;
                index = 0xE;
                p = D_003AB2E0 + 0xE;
            }
            index++;
            p++;
        } while (index < 0xE);
    }
    skey = (s16)value;
    vals = (s32 *)(arg3 + 0x24);
    index = 0;
    do {
        if (keys[index * 2] == skey) {
            result = vals[index * 2];
            index = 8;
        }
        index++;
    } while (index < 8);
    return result;
}
