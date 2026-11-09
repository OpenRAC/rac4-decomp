/* Not matching yet: BYTES 10/156 (tools/try_func.py func_01EF73F0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"
extern void *func_01EEDCD0(void *,const void *,s32);
extern char D_0019CEE8[];
typedef struct NetworkDefaults73 {
 u8 prefix[0x2c];
 s32 marker;
 u32 color;
 u8 baseTail[0x80];
 s32 mode;
 s32 enabled;
 f32 fraction;
 s32 fieldC0;
 s32 fieldC4;
 s32 fieldC8;
 s32 fieldCC;
 s32 fieldD0;
 s32 flagD4;
 s32 markerD8;
 u32 colorDC;
 u32 colorE0;
 s32 colorE4;
 s32 flagE8;
 s32 flagEC;
 s32 fieldF0;
} NetworkDefaults73;
/* BC is a float parsed by EF3164. Only six stores differ from retail; the copy helper retains its destination-pointer return. Other suffix field names record offsets without claiming original member names. */
/* Initializes a network record. */
void func_01EF73F0(NetworkDefaults73 *p)
{
    func_01EEDCD0((u8 *)p+0x38,D_0019CEE8,0x40);
    p->mode=14;
    p->enabled=1;
    p->marker=p->markerD8=-1;
    p->color=0xff0000ff;
    p->colorE0=p->colorDC=0xff00ff00;
    p->colorE4=-256;
    p->flagEC=p->flagE8=p->fieldD0=p->fieldCC=p->fieldC8=p->fieldC4=p->flagD4=p->fieldF0=p->fieldC0=p->fraction=0;
}
