/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011A518(void *, s32, s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_0051A740(void);
extern void func_L00_0051A7B8(s32);

void *func_L00_0051AE10(void) {
    s32 *object = func_L00_004FACD8(0x58);
    s32 v;
    if (object == 0) return 0;
    func_0011A518(object, 0, 0x58);
    v = func_L00_0051A740();
    object[1] = v;
    if (v == 0) goto failure;
    v = func_L00_0051A740();
    object[2] = v;
    if (v == 0) goto failure;
    v = func_L00_0051A740();
    object[3] = v;
    if (v == 0) goto failure;
    return object;
failure:
    if (object[1] != 0) func_L00_0051A7B8(object[1]);
    if (object[2] != 0) func_L00_0051A7B8(object[2]);
    if (object[3] != 0) func_L00_0051A7B8(object[3]);
    func_L00_004F84C8(0x18, 0x64, 0x21, 0, 0);
    return 0;
}
