#include "common.h"

typedef struct Type1 {
    char pad[0xE4];
    void *fE4[16];
    void *f124[16];
    void *f164[16];
    u8 f1A4[16];
    u8 f1B4[16];
} Type1;
extern void func_00502508(void *);

/* Clear all sixteen descriptors and their associated slot state. */
void func_00500C38(Type1 **holder)
{
    s32 i = 0;
    do {
        void *p = (*holder)->fE4[i];
        if (p)
            func_00502508(p);
        (*holder)->fE4[i] = 0;
        (*holder)->f124[i] = 0;
        (*holder)->f164[i] = 0;
        (*holder)->f1B4[i] = 0;
        (*holder)->f1A4[i] = 0;
        i++;
    } while (i < 16);
}
