/* Not matching yet: PAL main net.text func_01ED6380; 140 B / native 152 B.
 * Non-built WIP; not part of the build. No matching or semantic acceptance.
 * Ordered guards, positive byte/store branch and postcall join recovered.
 * ACTUAL EFFECT-ORDER FAILURE: the compiled callback SW to 0x001BCAB8
 * at +0x58 precedes context SW to 0x001BC8C0 at +0x60. Native requires
 * context before callback, as written below. Source order is not proof of
 * emitted order; this is a real failure, not allocation-only residue.
 * Initial rejection, input/base/prologue/call-delay and unreachable native
 * alignment-NOP differences also remain. No padding or forcing is used.
 * Current separate caller declares the second formal void*, while this
 * retained draft uses s32 callbackWord. Project-wide C consistency is open.
 * Existing handler_t conversion stores EE32 address bits only; no universal
 * callback signature, pointer-lifetime or portable-representation promise.
 * Primary: nine valid real relocation fields (four HI/LO pairs, one R26),
 * no GPREL and no allocated nontext data. Carriers/whole-link uncertified.
 * Future reproduction, only under authorized default PAL work:
 * python3 tools/check_func.py --version pal func_01ED6380 nonmatching/pal/net/func_01ED6380.c --diff
 */
#include "common.h"

typedef void (*handler_t)(s32, s32);

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_001BC838[];
extern handler_t D_001BCA30[];

s32 func_01ED5DD0(s32, s32, s32, s32);

s32 func_01ED6380(void *object, s32 callbackWord, s32 contextWord)
{
    if (D_00169CD0 != 1) {
        return -0xF;
    }
    if (D_00169CD4 == 0) {
        return -0x10;
    }
    if (object == NULL) {
        return -0x15;
    }
    if (*(s8 *)((u8 *)object + 0x15) == 0) {
        return -0x15;
    }
    *(s8 *)((u8 *)object + 0x25) = 0;
    *(s8 *)((u8 *)object + 0x14) = 0;
    D_001BC838[2] = contextWord;
    D_001BCA30[2] = (handler_t)(u32)callbackWord;
    return func_01ED5DD0(1, 5, 0x26, (s32)(u32)object) == 0 ? 0 : -5;
}
