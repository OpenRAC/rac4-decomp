#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    char _p0[0xBC];
    s32 fBC;
};


s32 func_00477770(Type1 *arg0) {
    s16 temp_a0;

    if ((arg0 != NULL) && ((temp_a0 = arg0->fBC, (temp_a0 == 0x10E)) || (temp_a0 == 0xE7D) || (temp_a0 == 0x1BC3) || (temp_a0 == 0x2569) || (temp_a0 == 0x2692))) {
        return 1;
    }
    return 0;
}
