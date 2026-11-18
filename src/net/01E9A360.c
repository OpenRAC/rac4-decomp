/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Blk {
    s32 f0;
    char pad4[0xC];
    char f10[0x100];
    char f110[0x70];
} Blk;

extern char *func_0011AFC8(char *, char *, s32);
extern void func_00127568(void *, s32);
extern void func_001294F0(char *fmt, ...);
extern s32 func_0012A718();
extern char D_00193FE0[];
extern char D_00194048[];
extern char D_00194098[];
extern char D_001940C8[];
extern char D_00194188[];
extern Blk D_1AD040[];
extern char D_1AD1C0[];
extern s32 D_1AD1EC[];

// Validates a 64-byte aligned buffer, records the buffer and two names in the shared block and starts the request.
s32 func_01E9A360(char *name0, char *name1, s32 buf) {
    Blk *b = D_1AD040;

    if (D_1AD1EC[0] == 0) {
        func_001294F0(D_00193FE0, D_00194188);
        func_001294F0(D_00194048);
        return -1;
    }
    if (buf & 0x3F) {
        func_001294F0(D_00193FE0, D_00194188);
        func_001294F0(D_001940C8, buf, 0x40);
        return -0x16;
    }
    func_00127568((void *)buf, buf + 0x133F);
    b->f0 = buf;
    func_0011AFC8(b->f10, name0, 0xFF);
    func_0011AFC8(b->f110, name1, 0x6F);
    func_0012A718(D_1AD1C0, 2, 0, b, 0x180, b, 4, 0, 0);
    func_001294F0(D_00193FE0, D_00194188);
    func_001294F0(D_00194098, b->f0);
    return b->f0;
}
