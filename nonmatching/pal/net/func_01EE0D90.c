/* Not matching yet: PAL WIP; main net.text 0x01EE0D90, 136B. Not part of the build. */
/*
 * Terminal positive action still merges into one compiled store; 128B versus native136B. Real
 * assertion strings/helper relocations are valid; return/store layout remains.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: a8683ce038e8bf0ed48eadf0d1e46ab3668e1a1ed6e5e126eca385df5f2cc413
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EE0D90 nonmatching/pal/net/func_01EE0D90.c --diff
 */
#include "common.h"

extern char D_00199F28[];
extern char D_PAL_MAIN_0019A438[];
void func_0011EAA0(char *, s32, char *);
void func_01EE0E18(s32, s32, s32);

/* Complete the positive action directly; otherwise send before updating state. */
s32 func_01EE0D90(s32 *state, void *payload, s32 length)
{
    if (length != 2)
        func_0011EAA0(D_00199F28, 0x573, D_PAL_MAIN_0019A438);
    if (*(u8 *)((u8 *)payload + 1) != 0) {
        *state = 0x31;
        return length;
    }
    func_01EE0E18((s32)state, 1, 0);
    *state = 0x31;
    return length;
}
