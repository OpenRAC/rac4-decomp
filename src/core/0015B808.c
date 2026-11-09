/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

extern s32 func_00161128(void),func_00161158(void);
extern void func_0015B7E0(void);
typedef struct { u8 pad0[0x20]; s32 f20; u8 pad24[0x46c]; s32 f490, f494; u8 pad498[0x174]; s32 f60C; } Type1;
extern Type1 D_00172160;
/* Update the named fields of the shared record. */
void func_0015B808(void)
{
    s32 first=func_00161128();
    Type1 *p=&D_00172160;
    p->f490=first;
    p->f60C=func_00161158();
    p->f494=p->f20;
    func_0015B7E0();
}
