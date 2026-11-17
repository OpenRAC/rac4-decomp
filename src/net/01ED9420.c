/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; } Pair;
typedef struct { s32 w[5]; } Blk;
extern Pair D_001B7908;
extern Pair D_001B7910;
extern Blk D_001B7918;
extern void *func_0011A518(void *, s32, u32);
extern s32 func_01EDA870(void);
extern void func_01ED93E8(void);
void func_01ED9420(void) {
    func_0011A518(&D_001B7908, 0, sizeof(Pair));
    D_001B7908.f0 = 0;
    D_001B7908.f4 = 0;
    func_0011A518(&D_001B7910, 0, sizeof(Pair));
    D_001B7910.f0 = func_01EDA870();
    D_001B7910.f4 = func_01EDA870();
    func_0011A518(&D_001B7918, 0, sizeof(Blk));
    func_01ED93E8();
}
