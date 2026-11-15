/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x4];
    s32 f4;
};

typedef struct Type2 Type2;
struct Type2 {
    char _p0[0x8];
    s32 f8;
    char _p1[0xC];
};

s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_004F8BE0(Type1 *self, s32 a1);
extern Type2 D_004A0640[];
extern Type1 *D_004A1888[];

/* Returns the slot for index arg0 in D_004A0640, or the entry from D_004A1888's lookup; NULL on failure. */
void *func_L00_0051C858(u32 arg0) {
    s32 local[12];
    s32 *p;

    if (arg0 < 0x8CU) {
        if (arg0 != 0 && D_004A0640[arg0].f8 == 0) {
            func_L00_004F84C8(8, 0x67, 0x65, 0, 0);
            return NULL;
        }
        return &D_004A0640[arg0];
    }
    if (D_004A1888[0] == NULL) {
        return NULL;
    }
    local[0] = 3;
    local[1] = (s32)&local[4];
    local[6] = arg0;
    p = (s32 *)func_L00_004F8BE0(D_004A1888[0], (s32)local);
    if (p != NULL) {
        return ((Type1 *)p)->f4;
    }
    func_L00_004F84C8(8, 0x67, 0x65, 0, 0);
    return NULL;
}
