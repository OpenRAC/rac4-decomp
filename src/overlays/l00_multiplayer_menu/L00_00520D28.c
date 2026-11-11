/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004E4F28 (src/levels/39_multiplayer_menu/L39_004E4970.c, GPL-3.0), the same code in both games. */

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
} Type1;
extern Type1 *func_L00_00520E90(void);
extern void func_L00_00520E08(Type1 *);
s32 func_L00_00520D28(Type1 *arg0) {
    Type1 *obj = func_L00_00520E90();
    func_L00_00520E08(obj);
    *obj = *arg0;
    return 0;
}
