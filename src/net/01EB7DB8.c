/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; } Ent_c;
typedef struct { s32 f0; s32 f4; s32 f8; char pad[0x44]; } Ent_50;
extern void func_01EB8908();
extern void func_01EBD390(void *arg0, void *arg1);
extern void func_01EBE4D8();

// Frees the buffers owned by a connection's slots and tables, then resets its state fields.
void func_01EB7DB8(u8 *arg0) {
    Ent_50 *e;
    Ent_c *tab;
    Ent_c *t;
    u16 i;

    if (arg0 == NULL) {
        return;
    }
    i = 0;
    func_01EB8908();
    e = *(Ent_50 **)(arg0 + 0x184);
    if (*(u16 *)(arg0 + 0x19C) != 0) {
        do {
            if (e->f0 != 0) {
                if (e->f4 != 0) {
                    func_01EBE4D8(*(s32 *)arg0, e->f4);
                }
                if (e->f8 != 0) {
                    func_01EBE4D8(*(s32 *)arg0, e->f8);
                }
                func_01EBD390(arg0, e);
                e->f4 = 0;
                e->f8 = 0;
            }
            i = i + 1;
            e++;
        } while (i < *(u16 *)(arg0 + 0x19C));
    }
    i = 0;
    tab = (Ent_c *)(arg0 + 4);
    do {
        t = tab + i;
        if (t->f0 != 0) {
            func_01EBE4D8(*(s32 *)arg0, t->f0);
            t->f0 = 0;
        }
        i = i + 1;
    } while (i < 0x20);
    *(s16 *)(arg0 + 0x1A0) = 0;
    *(s16 *)(arg0 + 0x1A2) = -2;
    *(s16 *)(arg0 + 0x1A4) = -2;
    *(s16 *)(arg0 + 0x1E0) = 1;
}
