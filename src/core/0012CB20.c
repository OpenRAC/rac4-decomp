/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern char *func_0011AFC8(char *, char *, s32);
extern s32 func_0012A718();
extern s32 func_0012C4B8(void);
extern s32 func_0012C5B8(void);
extern char D_001A9508[];
extern char D_001A9700[];

/* copies a name into the request buffer and sends it */
s32 func_0012CB20(char *name) {
    char *buf;
    if (func_0012C4B8() < 0) {
        return (s32)0xFFFF0000u;
    }
    if (func_0012C5B8()) {
        return (s32)0xFFFEFFFCu;
    }
    func_0011AFC8(D_001A9508, name, 0xFC);
    buf = D_001A9508 - 8;
    buf[0x103] = 0;
    if (func_0012A718(D_001A9700, 9, 0, buf, 0x200, buf, 4, 0, 0) < 0) {
        return (s32)0xFFFEFFFFu;
    }
    return *(s32 *)buf;
}
