#include "common.h"

/* Calls func_0048A950 on the record found for arg1 unless arg0 is set or the record's first word is 0xFFFFFFFF. */
extern void func_0048A950(void *arg0);
extern void *func_0048A970(u32 arg0);

void func_0048AF98(s32 arg0, s64 arg1) {
    s32 *temp_v0;

    temp_v0 = func_0048A970((u32) arg1);
    if (temp_v0 != NULL) {
        if (arg0 == 0) {
            if (*temp_v0 != 0xFFFFFFFF) {
                func_0048A950(temp_v0);
            }
        }
    }
}
