/* cflags: @ee29 -O2 -G0 -ffast-math -Wuninitialized */
#include "common.h"
extern void func_L00_004F84C8(int, int, int, int, int);
extern void *func_L00_004FACD8(unsigned int);
extern int func_L00_004FDF18(void *, int);
typedef struct Inner { int pad[12]; int ready; void *value; } Inner;
typedef struct Outer { char pad[80]; Inner *inner; char pad2[188]; unsigned int size; int other; } Outer;
int func_L00_004FDE68(Outer *p)
{
    void *value;
    unsigned int size;
    if (!p->inner->ready && !func_L00_004FDF18(p, p->other)) goto fail;
    if (p->inner->value) goto success;
    size = p->size;
    if (size - 1 > 0x8000) { p->size = 0x8001; size = 0x8001; }
    value = func_L00_004FACD8(size);
    if (!value) goto fail;
    p->inner->value = value;
success:
    return 1;
fail:
    func_L00_004F84C8(20, 219, 33, 0, 0);
    return 0;
}
