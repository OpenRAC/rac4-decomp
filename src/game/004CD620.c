#include "common.h"
typedef struct {
    char pad[0x23];
    unsigned char alpha;
} Object;
typedef struct {
    char pad[0x20];
    Object *a, *b, *c;
    char tail[0x38];
} State;
extern State D_0030EAA0[];
extern int func_00505B20(void);
void func_004CD620(int flag)
{
    State *p = &D_0030EAA0[func_00505B20()];
    if (p->b && p->c && p->a) {
        if (flag) {
            p->b->alpha = 0;
            p->c->alpha = 0;
            p->a->alpha = 128;
        } else {
            p->b->alpha = 128;
            p->c->alpha = 128;
            p->a->alpha = 0;
        }
    }
}
