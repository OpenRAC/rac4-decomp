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
    void *f48[96];
} Type3;

typedef struct Type5 {
    char _p0[0x58];
    void *f58;
    char _p5C[0x238 - 0x5C];
    u32 f238;
    s32 f23C;
    s32 f240;
    char _p244[0x24C - 0x244];
    void *f24C;
    char _p250[0x260 - 0x250];
    f32 f260;
    f32 f264;
} Type5;

extern void *func_L00_0071ED58(void *);
extern void func_L00_0071ADF0(Type1 *, u32, s32, char *);
extern void func_L00_0071AE38(void *, u32, s32, s32, s32, s32);
extern void func_L00_0071EE50(void *, Type3 *);
extern const char *func_0045E850(s32);
extern u8 D_004B9D48[];

/* Initialize the object and build its four local message records. */
void *func_L00_0071E250(void *arg0) {
    Type2 record0;
    Type2 record1;
    Type4 record2;
    Type4 record3;
    Type3 descriptor;
    Type3 *list;
    Type5 *object = arg0;
    const char *text;

    func_L00_0071ED58(arg0);
    object->f58 = D_004B9D48;
    object->f238 = 0xFFFFFFFFU;
    object->f23C = 29;
    object->f240 = 0x51000000;
    object->f24C = (u8 *)arg0 + 0x364;

    text = func_0045E850(0xFDF);
    record0.f0.word = -1;
    func_L00_0071ADF0(&record0.f0.f0, 0xFFFFFFFFU, 0, 0);
    func_L00_0071AE38(&record0, 0xFFFFFFFFU, 0, 0, 0x5100000F, (s32)text);

    {
        s32 state, value;
        state = object->f240;
        record1.f0.word = -1;
        value = state | 0xD;
        func_L00_0071ADF0(&record1.f0.f0, 0xFFFFFFFFU, 0, 0);
        func_L00_0071AE38(&record1, 0xFFFFFFFFU, 0, 0, value, 0);
    }

    record2.word = -1;
    func_L00_0071ADF0(&record2.f0, 0xFFFFFFFFU, 0, 0);
    {
        s32 state, value;
        state = object->f240;
        record2.word = 0;
        value = state | 8;
        text = func_0045E850(0x177);
        record3.word = -1;
        func_L00_0071ADF0(&record3.f0, 0xFFFFFFFFU, value, (char *)text);
        record3.word = 0;
    }

    list = &descriptor;
    list->f0.word = -1;
    func_L00_0071ADF0(&list->f0.f0, 0xFFFFFFFFU, 0, 0);
    list->f40 = -1;
    descriptor.f44 = 4;
    descriptor.f48[1] = &record1;
    descriptor.f48[2] = &record2;
    descriptor.f48[3] = &record3;
    descriptor.f48[0] = &record0;
    func_L00_0071EE50(arg0, list);
    object->f264 = -1.0f;
    object->f260 = -1.0f;
    return arg0;
}
