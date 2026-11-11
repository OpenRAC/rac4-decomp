/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C4CA8 (src/levels/39_multiplayer_menu/L39_004C4B30.c, GPL-3.0), the same code in both games. */

typedef struct E_004C4CA8 E_004C4CA8;
struct E_004C4CA8 {
    E_004C4CA8 *f0;
    E_004C4CA8 *f4;
    E_004C4CA8 *f8;
};
typedef struct {
    char _p0[0x68];
    E_004C4CA8 f68;
    E_004C4CA8 f74;
    void (*f80)(void *);
} Type1;
extern void func_L00_0051A628(void *);
void func_L00_00500AA8(Type1 *arg0) {
    E_004C4CA8 *list[2];
    s32 i;
    list[0] = &arg0->f68;
    list[1] = &arg0->f74;
    for (i = 0; i < 2; i++) {
        if (list[i]->f8 != 0) {
            func_L00_0051A628(list[i]->f8);
            list[i]->f8 = 0;
        }
        if (list[i]->f4 != 0) {
            arg0->f80(list[i]->f4);
            list[i]->f4 = 0;
            list[i]->f0 = 0;
        }
    }
}
