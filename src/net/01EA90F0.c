/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 { char _p0[4]; struct Type1 *next; char _p8[8]; s32 id; } Type1;
extern Type1 **D_0016819C;
Type1 *func_01EA90F0(s32 id) {
    Type1 *p = *D_0016819C;
    if (p != NULL && p->id != id) {
        Type1 *first = p;
        p = p->next;
        while (1) {
            if (p == first) {
                p = NULL;
            }
            if (p == NULL) {
                break;
            }
            if (p->id == id) {
                break;
            }
            p = p->next;
        }
    }
    return p;
}
