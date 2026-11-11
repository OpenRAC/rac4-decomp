/* Not matching yet: SIZE ours 48 / retail 52 (tools/try_func.py func_01F04C40 --diff). Not part of the build. */
#include "common.h"

/* Clear ten words and the word ten after each of them, then two more. */
void func_01F04C40(s32 *arg0) {
    u32 i;

    for (i = 0; i < 10; i++) {
        arg0[i] = 0;
        arg0[i + 0xB] = 0;
    }
    arg0[0x15] = 0;
    arg0[0xA] = 0;
}
