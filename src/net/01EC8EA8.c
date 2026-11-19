/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct {
    char pad[0x138];
    s32 f138;
} Type1;

extern Type1 *D_00167F38;
extern s32 *D_1B6A50;

s32 func_01EC8EA8(s32 a0, u32 i) {
    if (D_00167F38 != 0 && a0 != 0 && a0 == D_00167F38->f138 &&
        i < 0x100 && D_1B6A50 != 0) {
        return D_1B6A50[i];
    }
    return 0;
}
