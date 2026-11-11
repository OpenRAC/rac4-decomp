#include "common.h"
/* Ported from rac3-decomp's func_L39_006AB700 (src/levels/39_multiplayer_menu/L39_006AB098.c, GPL-3.0), the same code in both games. */

extern void *func_0011AFC8(void *, const char *, s32);
extern void func_L00_00741910(void *);
typedef struct Type1 { char pad[0x280]; char *f2C4; u8 name[0xC8]; s32 f390; } Type1;
void func_L00_007416D8(Type1 *self, char *a1) {
    u8 *p;
    self->f2C4 = a1;
    func_0011AFC8(self->name, a1, 0xC8);
    func_L00_00741910(self);
    self->f390 = 0;
    p = self->name;
    while (*p != 0) {
        p++;
        self->f390++;
    }
}
