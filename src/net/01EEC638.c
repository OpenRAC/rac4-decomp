/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef void (*Type2)(Type1 *, s32, f32, f32, s32, char *, s32, s32, s32, s32);
typedef struct Type3 {
    char c[0x32];
} Type3;

extern void func_0011A518(void *, s32, s32);
extern char *func_0011AFC8(char *, char *, s32);

/* Copies up to 0x32 bytes of arg3 into a local buffer (cutting arg3 at 0x32 when long), then forwards its arguments through the object's slot 0x10. */
void func_01EEC638(Type1 *arg0, s32 arg1, f32 fa, f32 fb, s32 arg2, char *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    char buf[0x33];
    u8 *p;

    func_0011A518(buf, 0, 0x33);
    if (arg4 >= 0x33) {
        *(Type3 *)buf = *(Type3 *)arg3;
        arg4 = 0x32;
        arg3[0x32] = 0;
    } else {
        func_0011AFC8(buf, arg3, arg4 + 1);
    }
    p = *(u8 **)arg0;
    p = *(u8 **)(p + 0x10);
    ((Type2)p)(arg0, arg1, fa, fb, arg5, arg3, arg4, arg2, 0, arg7);
}
