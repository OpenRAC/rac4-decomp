/* Not matching yet: PAL WIP; final predicate normalization differs. Not part of the build.
 * Primary identity: PAL level_00 .text 0x005C48C8, 356 bytes; shared catalogue has 14 placements.
 * Preserved B79 h01 body. Input and actual CompiledSource are byte-equal. Two unchanged
 * default PAL trials produced one 352-byte text; no source-body edits are made here.
 * Primary object recovers the early positive region and required conditional/fresh reads.
 * Residual: generated SLTU versus native result-copy/BNEZ/literal-one/zero; the shorter
 * return/restore region shifts branch targets. Native unused a0 setup at the exact
 * no-argument status call is omitted; no dummy argument is supplied.
 * Primary three R26 bindings and GPREL16 displacement -0x72CB are valid; no allocated data.
 * Full 14-carrier/five-physical-cell bindings and dynamic callback-provider contract
 * remain uncertified. Final helper func_00540A00 is NONMATCH, not a matched dependency.
 * Working contracts: s32(void *, void *); getter uses canonical signed address words;
 * status is s16(void). These do not prove unique original prototypes or whole C linkage.
 * Historical missing/timeout source and output artifacts remain UNKNOWN.
 * Reproduce with the unchanged default PAL pipeline, without extra flags:
 * python3 tools/check_func.py --version pal func_L00_005C48C8 nonmatching/pal/shared/func_L00_005C48C8.c --diff
 */
#include "common.h"

extern s32 D_0021E734;
extern s32 func_00510DE0(s32);
extern s16 func_0047BC10(void);
extern s32 func_00540A00(void *, s32);

s32 func_L00_005C48C8(void *context, void *object)
{
    u8 *ctx = (u8 *)context;
    u8 *obj = (u8 *)object;
    s16 tag = *(s16 *)(obj + 0xBC);
    void *capturedState;
    void *descriptor;
    s32 mode;
    s32 status;
    u8 subtype;

    if (tag == 0x210D)
        return 1;
    if (obj[0x31] == 0)
        return 0;
    if (tag == 0x19C0 || tag == 0x1AE6 || tag == 0x244B || tag == 0x209A)
        return 0;
    if (object == (void *)*(s32 *)(ctx + 0xBC))
        return 0;
    if ((*(u16 *)(obj + 0x34) & 0x1000) == 0)
        return 0;
    if (*(void **)(obj + 0x24) == NULL)
        return 0;

    capturedState = *(void **)(ctx + 0x130);
    descriptor = (void *)func_00510DE0((s32)object);
    mode = D_0021E734;
    if (descriptor != NULL && mode == 1) {
        if ((*(s32 (**)(void *, s32))((u8 *)*(void **)((u8 *)descriptor + 0x14) + 0x1C))
                (descriptor, *(s32 *)((u8 *)capturedState + 0x2F14)) != 0)
            return 0;
    }

    status = func_0047BC10();
    subtype = *((u8 *)*(void **)(obj + 0x24) + 0x46);
    if (subtype == 5 || status == 0x40)
        return 1;
    if (subtype == 0x11) {
        tag = *(s16 *)(obj + 0xBC);
        if ((tag == 0x2077 || tag == 0x253A) && capturedState != NULL &&
                *(s32 *)((u8 *)capturedState + 0x2318) == 0xD)
            return 1;
    }

    if (*((u8 *)*(void **)(obj + 0x24) + 0x46) != 0xD)
        return 0;
    return func_00540A00(object,
        *(s32 *)((u8 *)*(void **)(ctx + 0x130) + 0x2F14)) != 0;
}
