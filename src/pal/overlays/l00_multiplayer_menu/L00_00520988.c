/* cflags: @ee29 -O2 -G0 -Wuninitialized */
#include "common.h"

typedef struct Type1 {
    u8 f0[4];
    int f4;
    u8 f8[4];
    void **fC;
} Type1;

extern void *func_L00_00520AA8(void);
extern void func_L00_00520AF8(void *);
extern int func_L00_00520C70(void *, void *, int);

/* Add the non-null entries to an existing or newly allocated record list. */
void *func_L00_00520988(void *a1, Type1 *a2, int a3)
{
    void *v5;
    int v6;
    int v8;
    void *v10;

    if (!a1) {
        v5 = func_L00_00520AA8();
        if (!v5)
            return 0;
    } else {
        v5 = a1;
    }
    v8 = 0;
    v6 = a2->f4;
    if (v6 > 0) {
        do {
            v10 = a2->fC[v8];
            if (v10) {
                if (func_L00_00520C70(v5, v10, a3))
                    goto fail;
                v6 = a2->f4;
            }
            v8++;
        } while (v8 < v6);
    }
    return v5;

fail:
    func_L00_00520AF8(v5);
    return 0;
}
