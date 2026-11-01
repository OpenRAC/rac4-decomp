#include "common.h"

extern u64 func_0012E370(void);
extern s64 func_0012FEB0(s64 arg0, s64 arg1);

// Fetch the current handle and pass it with 0x24000 to func_0012FEB0.
void func_L00_0077E000(void) {
    func_0012FEB0(func_0012E370(), 0x24000);
}
