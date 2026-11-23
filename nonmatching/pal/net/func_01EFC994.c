/* Not matching yet: PAL WIP; main net.text 0x01EFC994, 128B. Not part of the build. */
/*
 * Actual compiler still loads object+B0 after the second result store, contrary to the required
 * native read-before-store region. Loop topology, compare gap and restoration also differ; source
 * capture alone is not emitted-effect proof.
 * No match, masked-score, source-ABI or binding approval is implied.
 * Retained source SHA256: 986de4e154485d1365902701b1dcf78247ba74fdaa499e7ec238274b39fbc647
 * Reproduce when separately authorized: python3 tools/check_func.py --version pal
 *   func_01EFC994 nonmatching/pal/net/func_01EFC994.c --diff
 */
#include "common.h"

s32 func_01EFCE48(char *, s32);

/* Update the two words until the virtual measurement reaches its threshold. */
void func_01EFC994(void *object)
{
    f32 (*method)(void *, s32, s32);
    void *table;
    s32 next;
    f32 measured;

    table = *(void **)((u8 *)object + 0xB0);
    method = *(f32 (**)(void *, s32, s32))((u8 *)table + 0x7C);
    for (;;) {
        measured = method(object,
                          *(s32 *)((u8 *)object + 0x2DC),
                          *(s32 *)((u8 *)object + 0x2C0));
        if (!(*(f32 *)((u8 *)object + 0x4E4) < measured))
            return;
        *(s32 *)((u8 *)object + 0x2DC) =
            func_01EFCE48((char *)object + 0xB8,
                         *(s32 *)((u8 *)object + 0x2DC));
        next = func_01EFCE48((char *)object + 0xB8,
                            *(s32 *)((u8 *)object + 0x2E0));
        table = *(void **)((u8 *)object + 0xB0);
        *(s32 *)((u8 *)object + 0x2E0) = next;
        method = *(f32 (**)(void *, s32, s32))((u8 *)table + 0x7C);
    }
}
