#include "common.h"

/* Calls the method at +0x2C of each object in the null-terminated list that starts at +4 of the object func_01EF2CC4 returns. */
extern void *func_01EF2CC4(void);
void func_01EE918C(void) {
    void **p = (void **)func_01EF2CC4();
    void **e;
    void *f;
    if (p[1] != 0) {
        e = p + 1;
        do {
            p = (void **)*e;
            f = *p;
            f = ((void **)f)[11];
            e++;
            ((void (*)(void *))f)(p);
        } while ((f = *e) != 0);
    }
}
