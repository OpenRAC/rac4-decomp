/* Not matching yet: BYTES 8/48 (tools/try_func.py func_01EEF25C --diff). Not part of the build. */
#include "common.h"

extern void func_01EE7620();

// Release the two handles at 0xA4 and 0xA8.
void func_01EEF25C(u8 *arg0) {
    func_01EE7620(*(s32 *)(arg0 + 0xA4));
    func_01EE7620(*(s32 *)(arg0 + 0xA8));
}
