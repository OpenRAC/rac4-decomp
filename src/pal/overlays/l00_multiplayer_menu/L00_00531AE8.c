/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_003FEC08();
extern void func_003FEC70(void *, void *);

s32 func_L00_00531AE8(void *arg0, void *arg1) {
    func_003FEC70(arg0, arg1);
    func_003FEC08((u8 *)arg0 + 0x80, (u8 *)arg1 + 8);
    func_003FEC70((u8 *)arg0 + 0x100, (u8 *)arg1 + 0x10);
    return 0;
}
