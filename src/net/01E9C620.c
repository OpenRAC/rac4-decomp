/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *,s32,s32);
extern s32 func_01E9D828(void *,s32,void *);
/* Prepares and sends a request. */
void func_01E9C620(s32 a,s32 b,u8 *p)
{
 s32 request[4]; s32 response[20]; response[17]=0; response[16]=0; func_0011A518(request,0,12); request[0]=2; request[1]=*(s32*)(p+0x10); func_01E9D828(request,12,response);
}
