/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

typedef struct { char pad[0xa4]; void *fa4; void *fa8; } Type1;
extern void func_01EE7620(void *);
/* Process both stored objects. */
void func_01EEF25C(Type1 *p)
{
    func_01EE7620(p->fa4);
    func_01EE7620(p->fa8);
}
