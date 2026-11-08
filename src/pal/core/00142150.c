#include "common.h"

typedef struct { u8 pad[0xC4]; s32 xC4; u8 pad2[0x24]; s32 xEC; s32 xF0; s32 xF4; s32 xF8; } T_135C10;
typedef struct { u8 pad[0x40]; T_135C10 *x40; } S_135C10;
extern void func_001418E8(S_135C10 *);

/* PAL: from rac3-decomp's func_00135C10 */
void func_00142150(S_135C10 *p, u32 a, s32 b) {
    T_135C10 *q = p->x40;
    q->xC4 = 1;
    q->xEC = (a & 0x0FFFFFFF) | 0x20000000;
    q->xF8 = b;
    q->xF4 = 0;
    q->xF0 = 0;
    func_001418E8(p);
}
