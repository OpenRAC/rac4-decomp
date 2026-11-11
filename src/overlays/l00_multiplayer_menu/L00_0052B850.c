/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    s32 unk0;
    u32 len;
    s32 unk8;
    u8 *base;
    u8 *cur;
} Buf;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 handle;
} Chan;

typedef union {
    u64 flags;
    u8 bytes[8];
} Flags;

extern s32 func_0011A2DC(void *, void *, s32);
extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_0051A708(s32);
extern void func_00540840(s32, u8 *, u8 *, s32);
extern s32 func_00540E70(s32);
extern void func_L00_004F84C8(int, int, int, int, int);
extern void func_L00_00505D50(void *, s32, s32);
extern u8 D_004AF9B8[];

s32 func_L00_0052B850(u8 *obj, s32 arg1) {
    s32 pad;
    Buf *buf;
    s32 n;
    s64 len;
    s32 total;
    s32 handle;
    Chan *chan;
    s32 ready;
    s32 fill;
    s32 i;
    s32 last;
    s32 want;

    if (arg1 != 0) {
        chan = (Chan *)(obj + 0x74);
        buf = (Buf *)(*(u8 **)(obj + 0x54) + 0xCC);
    } else {
        chan = (Chan *)(obj + 0x68);
        buf = (Buf *)(*(u8 **)(obj + 0x54) + 0xB4);
    }
    handle = chan->handle;
    ready = 0;
    if (handle != 0) {
        ready = func_00540E70(handle);
    }
    if (*(s32 *)(obj + 0xB0) == 0 || handle == 0 || ready == 0) {
        func_0011A370(buf->base, buf->cur, buf->len);
        ready = (s32)buf->base;
        buf->cur = (u8 *)ready;
    } else {
        len = buf->len;
        n = func_0051A708(handle);
        if (n != 1 && arg1 != 0) {
            pad = n - (s32)len % n;
            fill = pad - 1;
            if (*(u64 *)(obj + 0x100) & 0x200) {
                if ((*(Flags **)(obj + 0x54))->flags & 8) {
                    fill = pad;
                }
            }
            for (i = (s32)len; i < (s32)len + pad; i++) {
                buf->cur[i] = fill;
            }
            len += pad;
            buf->len += pad;
        }
        total = (s32)len;
        func_00540840(handle, buf->base, buf->cur, total);
        if (n != 1 && arg1 == 0) {
            pad = buf->base[(s32)(len - 1)];
            last = pad;
            want = pad;
            pad++;
            if (*(u64 *)(obj + 0x100) & 0x200) {
                if (func_0011A2DC(*(u8 **)(obj + 0x54) + 0xC, D_004AF9B8, 8) == 0 && !(last & 1)) {
                    (*(Flags **)(obj + 0x54))->flags |= 8;
                }
                if ((*(Flags **)(obj + 0x54))->flags & 8) {
                    pad--;
                }
            }
            if ((s32)buf->len < pad) {
                func_L00_004F84C8(0x14, 0xD3, 0x81, 0, 0);
                func_L00_00505D50(obj, 2, 0x15);
                return 0;
            }
            for (fill = total - pad; fill < total; fill++) {
                if (buf->base[fill] != want) {
                    func_L00_004F84C8(0x14, 0xD3, 0x93, 0, 0);
                    func_L00_00505D50(obj, 2, 0x15);
                    return 0;
                }
            }
            buf->len -= pad;
        }
    }
    return 1;
}
