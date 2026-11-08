#include "common.h"

typedef struct S_567180 { struct S_567180 *next; s32 f4; s32 id; } S_567180;
extern S_567180 *D_004A9BA0[];

/* PAL: from rac3-decomp's func_L39_0066E338 */
S_567180 *func_L00_00567180(s32 id) {
    S_567180 *p = D_004A9BA0[0];
    while (p != 0) {
        if (id == p->id) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
