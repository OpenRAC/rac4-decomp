#include "common.h"

typedef struct Type1 {
    char _p0[4];
    s32 f4;
    s32 f8;
    char fC[0x33];
    char f3F;
} Type1;

typedef union Type4 {
    Type1 f0;
    s32 word;
} Type4;

typedef struct Type2 {
    Type4 f0;
    s32 f40;
    char f44[0xC8];
} Type2;

typedef struct Type3 {
    Type4 f0;
    s32 f40;
    s32 f44;
    Type2 *f48[96];
} Type3;

typedef struct Type5 {
    char _p0[0x58];
    void *f58;
    char _p5C[0x23C - 0x5C];
    s32 f23C;
    s32 f240;
    char _p244[0x24C - 0x244];
    void *f24C;
} Type5;

extern void *func_L00_0071ED58(void *);
extern void func_L00_0071ADF0(Type1 *, u32, s32, char *);
extern void func_L00_0071AE38(void *, u32, s32, s32, s32, s32);
extern void func_L00_0071EE50(void *, Type3 *);
extern u8 D_004BA1D8[];

/* Initialize the object, construct six message records and pass their descriptor. */
void *func_L00_007200A8(void *arg0) {
    Type2 record0;
    Type2 record1;
    Type2 record2;
    Type2 record3;
    Type2 record4;
    Type2 record5;
    Type3 descriptor;
    Type3 *list;
    Type5 *object = arg0;

    func_L00_0071ED58(arg0);
    object->f58 = D_004BA1D8;
    object->f23C = 2;
    object->f240 = 0x43000000;
    object->f24C = (u8 *)arg0 + 0x27C;

    record0.f0.word = -1;
    func_L00_0071ADF0(&record0.f0.f0, 0xFFFFFFFFU, 0, 0);
    func_L00_0071AE38(&record0, 0xFFFFFFFFU, 0x43000031, 0, 0x43000026, 0);

    {
        s32 state, value0, value1;
        state = object->f240;
        record1.f0.word = -1;
        value0 = state | 0x30;
        value1 = state | 0x25;
        func_L00_0071ADF0(&record1.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record1, 0xFFFFFFFFU, value0, 0, value1, 0);
    }

    {
        s32 state, value0, value1;
        state = object->f240;
        record2.f0.word = -1;
        value0 = state | 0x2F;
        value1 = state | 0x24;
        func_L00_0071ADF0(&record2.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record2, 0xFFFFFFFFU, value0, 0, value1, 0);
    }

    {
        s32 state, value0, value1;
        state = object->f240;
        record3.f0.word = -1;
        value0 = state | 0x2E;
        value1 = state | 0x22;
        func_L00_0071ADF0(&record3.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record3, 0xFFFFFFFFU, value0, 0, value1, 0);
    }

    {
        s32 state, value0, value1;
        state = object->f240;
        record4.f0.word = -1;
        value0 = state | 0x2D;
        value1 = state | 0x21;
        func_L00_0071ADF0(&record4.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record4, 0xFFFFFFFFU, value0, 0, value1, 0);
    }

    {
        s32 state, value0, value1;
        state = object->f240;
        record5.f0.word = -1;
        value0 = state | 0x2C;
        value1 = state | 0x20;
        func_L00_0071ADF0(&record5.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record5, 0xFFFFFFFFU, value0, 0, value1, 0);
    }

    list = &descriptor;
    list->f0.word = -1;
    func_L00_0071ADF0(&list->f0.f0, 0xFFFFFFFFU, 0, 0);
    list->f40 = -1;
    descriptor.f44 = 6;
    descriptor.f48[1] = &record1;
    descriptor.f48[2] = &record2;
    descriptor.f48[3] = &record3;
    descriptor.f48[4] = &record4;
    descriptor.f48[5] = &record5;
    descriptor.f48[0] = &record0;
    func_L00_0071EE50(arg0, list);
    return arg0;
}
