/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Decoder {
    u8 unknown0[0x1C0];
    u32 field1C0;
    u8 unknown1C4[0x664];
    u32 pending;
} Decoder;

extern s32 func_0012D420(void);
extern s32 func_0012D470(void);
extern s32 func_001469F8(s32 mode, s32 reserved);

void func_00141820(Decoder *decoder)
{
    s32 interrupts;
    decoder->pending = 1;
    decoder->field1C0 = 0;
    interrupts = func_0012D420();
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 | 0x10000;
    *(volatile u32 *)0x1000B000 = 0;
    *(volatile u32 *)0x1000B400 = 0;
    *(volatile u32 *)0x1000D400 = 0;
    *(volatile u32 *)0x1000F590 = *(volatile u32 *)0x1000F520 & 0xFFFEFFFFu;
    if (interrupts != 0)
        func_0012D470();
    *(volatile u32 *)0x1000B020 = 0;
    *(volatile u32 *)0x1000B420 = 0;
    *(volatile u32 *)0x1000D420 = 0;
    *(volatile u32 *)0x10002010 = 0x40000000;
    func_001469F8(0, 0);
}
