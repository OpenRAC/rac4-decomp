/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004DAF40 (src/levels/39_multiplayer_menu/L39_004DAF40.c, GPL-3.0), the same code in both games. */

extern void func_L00_00516C48(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
typedef struct Type1 { char pad[0x24]; struct Type1 *next; struct Type1 *prev; } Type1;
Type1 *func_L00_00516D40(Type1 *self, Type1 *child) {
    Type1 *tail;
    if (self == 0) return child;
    tail = self;
    while (tail->next != 0) tail = tail->next;
    tail->next = child;
    if (child != 0) child->prev = tail;
    func_L00_00516C48((s32)self, 6, 0, 0);
    return self;
}
