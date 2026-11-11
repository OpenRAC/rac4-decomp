/* Not matching yet: BYTES 16/712 (tools/try_func.py func_L00_0053C490 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

char *strcpy(char *, const char *);
s32 func_0012B338(void *, s32);
s32 func_0012B740(s32, s32, s32);
void func_L00_004F84C8(int, int, int, int, int);
void func_L00_0053C320(void *);

typedef struct {
    u8 pad0[0xC];
    s32 isOpen;
    s32 flag10;
    u8 pad14[0x8];
    s32 fd;
    s32 flags;
} Type1;

typedef struct {
    void *name;
    char *mode;
    s32 flags;
} Type2;

s32 func_L00_0053C490(Type1 *arg0, s32 arg1, s32 arg2, void **arg3) {
    char buf[64];
    Type2 req;
    s32 ret = 1;
    s32 fd;
    s32 flags;

    switch (arg1) {
    case 1:
        arg2 = 0;
    case 128: {
        s64 pos = arg2;
        if (func_0012B740(arg0->fd, pos, 0) != arg2) {
            ret = -1;
        }
        break;
    }
    case 3:
    case 133:
        ret = func_0012B740(arg0->fd, 0, 1);
        break;
    case 108:
        if (arg2 & 8) {
            if (arg2 & 2) {
                flags = 0x203;
                strcpy(buf, "SCE_CREAT | SCE_RDWR");
            } else {
                flags = 0x202;
                strcpy(buf, "SCE_CREAT | SCE_WRONLY");
            }
        } else if ((arg2 & 6) == 6) {
            flags = 3;
            strcpy(buf, "SCE_RDWR");
        } else if (arg2 & 4) {
            flags = 2;
            strcpy(buf, "SCE_WRONLY");
            flags = 0x602;
            strcpy(buf, "SCE_CREAT | SCE_TRUNC | SCE_WRONLY");
        } else if (!(arg2 & 2)) {
            func_L00_004F84C8(0x20, 0x6E, 0x64, 0, 0);
            ret = 0;
            break;
        } else {
            flags = 1;
            strcpy(buf, "SCE_RDONLY");
        }
        req.flags = flags;
        req.name = arg3;
        req.mode = buf;
        goto do_open;
    case 104:
        func_L00_0053C320(arg0);
        arg0->fd = *(s32 *)arg3;
        arg0->flag10 = arg2 & 1;
        arg0->isOpen = 1;
        break;
    case 105:
        ret = -1;
        if (arg0->isOpen != 0) {
            if (arg3 != NULL) {
                *(s32 *)arg3 = arg0->fd;
            }
            ret = arg0->fd;
        }
        break;
    case 136:
        req.name = arg3[0];
        req.mode = arg3[1];
    do_open:
        func_L00_0053C320(arg0);
        arg0->fd = *(s32 *)arg3;
        arg0->flag10 = arg2 & 1;
        fd = func_0012B338(req.name, req.flags);
        if (fd < 0) {
            ret = 0;
        } else {
            arg0->fd = fd;
            arg0->isOpen = 1;
        }
        break;
    case 8:
        ret = arg0->flag10;
        break;
    case 9:
        arg0->flag10 = arg2 & 1;
        break;
    case 11:
    case 12:
        ret = 1;
        break;
    case 2:
    case 106:
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
