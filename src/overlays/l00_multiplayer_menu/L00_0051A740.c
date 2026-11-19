/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_004FAD28(void *);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern s32 func_L00_00540E78(void *);

void *func_L00_0051A740(void) {
    u8 *p;
    u8 *q;

    p = func_L00_004FACD8(0x10);
    q = p;
    if (p != NULL) {
        *(s32 *)(p + 0x0) = 0;
        *(s32 *)(p + 0xC) = 0;
        *(s32 *)(p + 0x8) = 0;
        if (func_L00_00540E78(p) != 0) {
            return p;
        }
    }
    if (q != NULL) {
        func_004FAD28(q);
    }
    func_L00_004F84C8(6, 0x75, 0x21, 0, 0);
    return NULL;
}
