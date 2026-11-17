/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[8]; u8 f8; } Node;
typedef struct { char _p0[0xFC]; u32 fFC; } Ctx;
typedef void (*Handler)(s32, s32, u32);
extern Ctx *D_00167F38;
extern Handler *D_001B73B4;
extern Node *func_01EC98E8(s32);
void func_01EC9BA0(s32 a, s32 id, u32 code) {
    if (code < D_00167F38->fFC || code == (u32)-2 || code == (u32)-1) {
        Node *n = func_01EC98E8(id);
        if (n != 0) {
            Handler h = D_001B73B4[n->f8];
            if (h != 0) {
                h(a, id, code);
            }
        }
    }
}
