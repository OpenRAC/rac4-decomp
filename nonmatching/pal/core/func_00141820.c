/* Not matching yet on PAL: SIZE ours 144 / disc 200 (tools/check_func.py --version pal func_00141820 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
/* Retail builds each hardware register's address as a constant (lui/ori, then an access at 0):
 * only a cast of the number, `*(volatile u32 *)0x...`, gives that, and matched C may use neither
 * volatile nor hardcoded addresses. A global named by its address gives lui/%lo instead. */
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
extern u32 D_10002010;
extern u32 D_1000B000;
extern u32 D_1000B020;
extern u32 D_1000B400;
extern u32 D_1000B420;
extern u32 D_1000D400;
extern u32 D_1000D420;
extern u32 D_1000F520;
extern u32 D_1000F590;


void func_00141820(Decoder *decoder)
{
    s32 interrupts;
    decoder->pending = 1;
    decoder->field1C0 = 0;
    interrupts = func_0012D420();
    D_1000F590 = D_1000F520 | 0x10000;
    D_1000B000 = 0;
    D_1000B400 = 0;
    D_1000D400 = 0;
    D_1000F590 = D_1000F520 & 0xFFFEFFFFu;
    if (interrupts != 0)
        func_0012D470();
    D_1000B020 = 0;
    D_1000B420 = 0;
    D_1000D420 = 0;
    D_10002010 = 0x40000000;
    func_001469F8(0, 0);
}
