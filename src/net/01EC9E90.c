/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xC]; s32 fC; s32 f10; } Node;
typedef struct { char _p0[0x404]; s32 f404; } Sess;
extern Sess *D_001B7390;
extern Node *func_01EC98E8(s32);
extern s32 func_01EC9DD0(s32);
extern s32 func_01EC9858(s32);
extern void func_01EC9CB0(s32);
s32 func_01EC9E90(s32 id) {
    Sess *s = D_001B7390;
    Node *n;
    if (s == 0) {
        return 8;
    }
    n = func_01EC98E8(id);
    if (n == 0) {
        return 8;
    }
    if (n->f10 == s->f404) {
        func_01EC9DD0(id);
        return 0;
    }
    if (n->fC == s->f404) {
        func_01EC9858(id);
    }
    func_01EC9CB0(id);
    return 0;
}
