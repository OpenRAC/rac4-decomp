/* Not matched: PAL SCES_532.85.
 * Stored-object comparison: BYTES 3/176 (1 words differ).
 * Function text: 176 B; native catalogue: 176 B; 15 placement(s).
 * Instruction/size differences remain; symbol bindings, ownership and semantics also need review.
 * Relocated instruction fields are masked in this comparison, not certified targets.
 * Reproduce with the original compiler setup:
 * python3 tools/check_func.py --version pal func_00540A00 nonmatching/pal/game/func_00540A00.c --diff
 */
#include "common.h"

extern s32 D_0021EE54;
extern void *func_0053E038(void *);

/* Checks the live interface payload and the object's two flag bits. */
s32 func_00540A00(void *arg0, s32 arg1)
{
    void *payload;
    s32 mode;
    u8 flags;

    if (*(s32 *)((u8 *)arg0 + 0x98) != 0) {
        payload = func_0053E038(arg0);
        if (payload != NULL) {
            if (!(*(f32 *)((u8 *)payload + 0x2E8) <= 0.0f)) {
                mode = D_0021EE54;
                if (mode == 1) {
                    flags = *(u8 *)((u8 *)arg0 + 0xBE);
                    if (flags & 0x18) {
                        if (!(flags & 8) || arg1 != mode) {
                            if (flags & 0x10) {
                                if (arg1 == 0)
                                    return 0;
                            }
                            return 1;
                        }
                        return 0;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
