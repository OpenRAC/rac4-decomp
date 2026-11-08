#include "common.h"

typedef struct Node_566C80 {
    struct Node_566C80 *next;
    u8 pad4[4];
    s32 id;
} Node_566C80;
extern Node_566C80 *D_004A9BA0[];

/* from rac3-decomp's func_L39_0066E338 */
Node_566C80 *func_L00_00566C80(s32 id) {
    Node_566C80 *p = D_004A9BA0[0];
    while (p != 0) {
        if (id == p->id) {
            return p;
        }
        p = p->next;
    }
    return 0;
}
