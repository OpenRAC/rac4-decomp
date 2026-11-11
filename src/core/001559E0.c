/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct { u8 pad[5]; u8 f5, f6, f7; } Type2;
extern void func_00155908(Type2 *);
/* Decrement the counter and reset it when it reaches zero. */
void func_001559E0(unsigned char *p)
{
 if (p[3] == 0) { p[3] = 23; func_00155908((Type2 *)p); } else p[3]--;
}
