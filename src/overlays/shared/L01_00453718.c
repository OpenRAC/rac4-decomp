#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0x34];
    u16 f34;
    char _p36[0x62];
    s32 f98;
};

s32 func_00626818(void *, s32);


void func_L01_00453718(Type1 *arg0) {
    arg0->f98 = 0;
    arg0->f34 = (u16) ((arg0->f34 | 0x41) & 0xEFFF);
    func_00626818(arg0, 1);
}
