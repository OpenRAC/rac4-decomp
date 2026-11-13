/* Not matching yet: BYTES 1/184 (tools/try_func.py func_01EA04A0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

s32 func_01EA44C8(s32);

s32 func_01EA04A0(s32 *out, s32 arg1) {
    u32 arr[100];
    u32 *src;
    u32 a;
    u32 b;
    s32 i;
    s32 j;

    if (out == NULL) return 0x17;
    src = (u32 *)func_01EA44C8(arg1);
    if (src == NULL) return 0x16;
    i = 0;
    do {
        arr[i] = src[i];
        i++;
    } while (i < 100);
    for (i = 99; i > 0; i--) {
        for (j = 0; j < i; j++) {
            a = arr[j];
            b = arr[j + 1];
            if (b < a) {
                arr[j] = b;
                arr[j + 1] = a;
            }
        }
    }
    *out = arr[50];
    return 0;
}
