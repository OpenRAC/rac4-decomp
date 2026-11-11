/* cflags: -G0 */
#include "common.h"

typedef struct {
    s32 id;
    s32 a;
    s32 b;
    s32 kind;
} Entry;

extern void func_L41_006255D0(void);
extern Entry D_0036E050[16];

void func_L41_00625710(s32 id, s32 val, s32 kind) {
    s32 i;
    s32 slot;

    slot = -1;
    if (kind == 10) {
        return;
    }
    for (i = 0; i < 16; i++) {
        if (D_0036E050[i].id == id) {
            slot = i;
            break;
        }
        if (D_0036E050[i].id == -1 && slot == -1) {
            slot = i;
        }
    }
    if (slot >= 0) {
        if (D_0036E050[slot].kind != kind) {
            func_L41_006255D0();
        }
        D_0036E050[slot].id = id;
        D_0036E050[slot].a = val;
        D_0036E050[slot].b = val;
        D_0036E050[slot].kind = kind;
    }
}
