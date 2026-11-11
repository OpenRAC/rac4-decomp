/* cflags: -msplit-addresses */
#include "common.h"

extern s32 func_00122A28(void *, const char *, void *);
extern u8 *D_00163E74[];
/* Formats arguments into the current global stream. */
s32 func_0011D5D8(const char *fmt,...)
{
 u8 **slot=D_00163E74; u8 *p=*slot; *(u8**)(*(u8**)(p+8)+0x54)=p; return func_00122A28(*(void**)(*slot+8),fmt,(u8*)__builtin_next_arg(fmt)-0x38);
}
