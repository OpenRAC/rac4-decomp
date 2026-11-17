/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0xC]; void (*fC)(void); } Obj;
extern Obj *D_0016AC20;
void func_01EE1A10(Obj *o) {
    if (o != 0 && o->fC != 0) {
        o->fC();
        if (o == D_0016AC20) {
            D_0016AC20 = 0;
        }
    }
}
