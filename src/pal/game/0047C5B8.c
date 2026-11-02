#include "common.h"

extern char *func_0047C510(void *);
extern char *func_00476F70(void *);
/* Release the selected object's references from the owner. */
void func_0047C5B8(void *a)
{
    char *p = func_0047C510(a);
    if (p && *(void **)(p + 0x10) && *(short *)(p + 0x16) == 2) {
        char *q;
        int i;
        void **s;
        *(short *)(p + 0x16) = 1;
        q = func_00476F70(*(void **)(p + 0x10));
        if (q) {
            s = (void **)(q + 0x50);
            for (i = 7; i >= 0; i--, s++)
                if (*s == a)
                    *s = 0;
            *(int *)(q + 0x4C) -= *(int *)(p + 0x40);
        }
    }
}
