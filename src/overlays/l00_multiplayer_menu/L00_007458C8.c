#include "common.h"

typedef struct Part Part;
typedef struct {
    u8 pad0[0x20];
    void (*setMode)(Part *, s32, s32);
} PartVt;
struct Part {
    u8 pad0[0x58];
    PartVt *vt;
};

typedef struct {
    u8 pad0[0xB0];
    Part *parts[62];
} Model;

void func_L00_007458C8(Model *m) {
    s32 i;
    s32 j;

    m->parts[0]->vt->setMode(m->parts[0], 2, 0);
    m->parts[5]->vt->setMode(m->parts[5], 2, 0);
    for (j = 0; j < 5; j++) {
        m->parts[7 + j]->vt->setMode(m->parts[7 + j], 2, 0);
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 5; j++) {
            m->parts[12 + i * 5 + j]->vt->setMode(m->parts[12 + i * 5 + j], 2, 0);
        }
    }
}
