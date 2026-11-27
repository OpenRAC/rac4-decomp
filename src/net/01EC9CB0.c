/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    char _p0[4];
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Node;

extern u8 D_1B7258[];
extern void func_01EA06A8(s32 *arg0);
extern s32 *func_01EC8EA8(s32, s32);
extern s32 func_01EC9858(s32 id);
extern Node *func_01EC98E8(s32 arg0);
extern void func_01EC9C40(u32 a0, s32 a1);

s32 func_01EC9CB0(s32 arg0) {
    u8 *b;
    u8 *c;
    Node *ep[1];
    s32 tbl;
    s32 *g;
    s32 r = 8;

    b = D_1B7258;
    tbl = *(s32 *)(b + 0x138);
    if (tbl == 0) {
        return r;
    }
    ep[0] = func_01EC98E8(arg0);
    if (ep[0] == NULL) {
        return r;
    }
    func_01EC9C40(ep[0]->f10, arg0);
    ep[0] = func_01EC98E8(arg0);
    if (ep[0] != NULL) {
        func_01EC9858(arg0);
        ep[0]->f4 = 1;
        g = func_01EC8EA8(tbl, ep[0]->f10);
        if (g != NULL && (arg0 < g[2] || arg0 >= g[2] + g[3])) {
            ep[0]->f4 = 0;
        }
        func_01EA06A8((s32 *)((u8 *)ep[0] + 0x28));
        func_01EA06A8((s32 *)((u8 *)ep[0] + 0x24));
        func_01EA06A8((s32 *)((u8 *)ep[0] + 0x40));
        func_01EA06A8((s32 *)((u8 *)ep[0] + 0x44));
        func_01EA06A8((s32 *)ep);
        c = D_1B7258;
        *(s32 *)(*(s32 *)(c + 0x17C) + arg0 * 4) = 0;
    }
    return 0;
}
