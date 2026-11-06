/* cflags: -O2 -G8 -fno-opt-stack */
#include "common.h"

typedef struct Object {
    u64 magic;
    u8 unknown8[0x10];
    u8 type;
    u8 unknown19[3];
    void *data;
    u8 unknown20[0x10];
    void *buffer30;
    void *buffer34;
} Object;

extern void *(*D_0016F7C0[])(u32 count, u32 bytes);
extern u16 D_0016F7C8[];
extern s32 D_0016F7D0[];
extern s32 func_00150B78(void **data0, void **data1, void **data2);
extern s32 func_001516D8(Object **object0, Object **object1, Object **object2);

s32 func_001514F0(Object **out0, Object **out1, Object **out2)
{
    Object *first;
    Object *second;
    Object *third;

    if (out0 == 0 || out1 == 0 || out2 == 0) {
        return 0x181A;
    }
    *out0 = 0;
    *out1 = 0;
    *out2 = 0;

    first = D_0016F7C0[0](1, 0x38);
    if (first == 0) {
        return 0x1770;
    }
    *out0 = first;
    first->type = 0xB;
    first->magic = 0xFACE;

    second = D_0016F7C0[0](1, 0x38);
    if (second == 0) {
        return 0x1770;
    }
    *out1 = second;
    second->type = 0xB;
    second->magic = 0xFACE;

    third = D_0016F7C0[0](1, 0x38);
    if (third == 0) {
        return 0x1770;
    }
    *out2 = third;
    third->type = 0xB;
    third->magic = 0xFACE;

    if (D_0016F7D0[0] == 3) {
        first->buffer30 = D_0016F7C0[0](0x1000, 1);
        if (first->buffer30 == 0)
            return 0x1770;
        first->buffer34 = D_0016F7C0[0](0x1000, 1);
        if (first->buffer34 == 0)
            return 0x1770;
        second->buffer30 = D_0016F7C0[0](0x1000, 1);
        if (second->buffer30 == 0)
            return 0x1770;
        second->buffer34 = D_0016F7C0[0](0x1000, 1);
        if (second->buffer34 == 0)
            return 0x1770;
        third->buffer30 = D_0016F7C0[0](0x1000, 1);
        if (third->buffer30 == 0)
            return 0x1770;
        third->buffer34 = D_0016F7C0[0](0x1000, 1);
        if (third->buffer34 == 0)
            return 0x1770;
    }

    if (func_00150B78(&first->data, &second->data, &third->data) != 0) {
        func_001516D8(out0, out1, out2);
        return 0x1770;
    }
    D_0016F7C8[0]++;
    return 0;
}
