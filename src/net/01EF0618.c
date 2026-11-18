/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_0011A518(void *, s32, s32);
extern s32 func_0011A8A0(const char *, const char *);
extern s32 func_0011AB04(u8 *);
extern char *func_0011AFC8(char *, char *, s32);
extern void *func_01EEDCD0(void *, const void *, s32);
extern void func_01F0C090(char *arg0, s32 arg1);
extern s32 D_0016E444[];
extern char D_0019C540[];
extern char D_0019C570[];
extern char D_0019C580[];

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    char name[0x24];
    s32 f30;
} E_01EF0618;

/* Initialises an entry from a name string taken from the tail of arg3. */
void func_01EF0618(E_01EF0618 *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    char buf[0x20];
    char *name;

    name = arg0->name;
    arg0->f4 = arg2;
    arg0->f8 = arg1;
    arg0->f0 = 0;
    func_0011A518(buf, 0, 0x20);
    func_01EEDCD0(buf, arg3 + func_0011AB04(arg3) - 0x1E, 0x20);
    if (func_0011AB04((u8 *)buf) >= 0x20) {
        func_01F0C090(D_0019C540, 0x1DA);
    }
    func_0011A518(name, 0, 0x20);
    func_0011AFC8(name, buf, 0x1F);
    if (func_0011A8A0(name, D_0019C580) == 0) {
        func_01F0C090(D_0019C540, 0x1E2);
    }
    if (func_0011A8A0(buf, D_0019C570) != 0) {
        arg0->f30 = D_0016E444[0]++;
    } else {
        arg0->f30 = -1;
    }
}
