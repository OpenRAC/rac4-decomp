#include "common.h"

typedef struct Type2 {
    u8 pad0[4];
    s32 f4;
} Type2;

typedef struct Type5 {
    s32 f0;
    s32 f4;
} Type5;

typedef struct Type1 {
    Type2 *f0;
    s32 f4;
    s32 f8;
    s32 fC;
    Type5 *f10;
} Type1;

typedef struct Type6 {
    s32 head;
    s32 tail;
    s32 count;
    Type1 *ring[8];
} Type6;

extern void func_001634A8(s32 repeat);
extern void func_00163840(s32, s32, s32, s32, Type5 *, void (*)(void), s32);
extern s32 func_00163928(void);
extern void func_004996D8(void);
extern Type6 D_002F3BD0;

void func_00499790(void) {
    Type1 *e;

    if (D_002F3BD0.head == D_002F3BD0.tail) {
        return;
    }
    if (func_00163928() != 0) {
        return;
    }
    e = D_002F3BD0.ring[D_002F3BD0.head];
    if (e->f0 == 0) {
        D_002F3BD0.count--;
        D_002F3BD0.head = (D_002F3BD0.head + 1) % 8;
        if (D_002F3BD0.head == D_002F3BD0.tail) {
            return;
        }
        e = D_002F3BD0.ring[D_002F3BD0.head];
        while (e->f0 == 0) {
            D_002F3BD0.count--;
            D_002F3BD0.head = (D_002F3BD0.head + 1) % 8;
            if (D_002F3BD0.head == D_002F3BD0.tail) {
                return;
            }
            e = D_002F3BD0.ring[D_002F3BD0.head];
        }
        if (D_002F3BD0.head == D_002F3BD0.tail) {
            return;
        }
    }
    func_00163840(0, e->f0->f4, e->fC + e->f10->f0, e->f10->f4, e->f10, func_004996D8, 0);
    func_001634A8(1);
}
