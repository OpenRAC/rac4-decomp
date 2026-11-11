/* Not matching yet: BYTES 16/116 (tools/try_func.py func_01EF5938 --diff). Not part of the build. */
/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"
extern void *func_01EEDCD0(void *,const void *,s32);
extern char D_0019C8F0[];
typedef struct {
    u8 pad00[0x2c]; s32 f2c; u32 f30; u8 pad34[0x80];
    s32 fb4, fb8; f32 fbc; void *fc0; s32 fc4, fc8, fcc, fd0;
    u32 fd4, fd8;
} NetworkDefaults59;
/* BC is a float parsed by EF3164; C0 is a record lookup pointer. Remaining differences are constant registers and independent store scheduling. */
/* Initializes a network record. */
void func_01EF5938(NetworkDefaults59 *p)
{
    func_01EEDCD0((u8 *)p+0x38,D_0019C8F0,0x40);
    p->fd8=p->f30=p->fd4=0xff000000;
    p->fb4=14;
    p->fc4=p->fb8=1;
    p->fcc=p->f2c=-1;
    p->fd0=-256;
    p->fbc=0.0f;
    p->fc0=NULL;
}
