/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_01EA75C8(s32 *p);
extern s32 *func_01EA88C8(void);
extern s32 func_01EA8908(s32 a0);
extern s32 D_00167F34[];

typedef struct Pk16 {
    u64 a;
    u64 b;
} __attribute__((packed)) Pk16;

typedef struct Type2 {
    u32 f0;
    u32 f4;
} Type2;

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 (*f8)(void *, Type2, void *, void *, void *);
} Type1;

/* Allocates a request, copies or clears its 16-byte payload, sends it through the vtable and frees it on error. */
s32 func_01EA75F8(void **arg0, Type2 arg1, s32 arg2, Pk16 *arg3) {
    u8 *obj;
    u8 *payload;
    s32 r;

    *arg0 = 0;
    obj = (u8 *)func_01EA88C8();
    if (obj == 0) {
        return 3;
    }
    payload = obj + 0xC;
    if (arg3 != 0) {
        *(Pk16 *)payload = *arg3;
    } else {
        func_01EA75C8((s32 *)payload);
    }
    *(s32 *)(obj + 0x1C) = arg2;
    r = ((Type1 *)D_00167F34[0])->f8(obj + 8, arg1, obj + 0x1C, payload, obj + 0x20);
    if (r != 0) {
        func_01EA8908((s32)obj);
        return r;
    }
    *arg0 = obj;
    *(s32 *)(obj + 4) = 1;
    return r;
}
